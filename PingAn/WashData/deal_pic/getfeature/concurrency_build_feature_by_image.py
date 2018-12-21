#coding=utf-8

import os,re,sys,shutil
import requests
import json
import hashlib
import base64
import time
import random
from multiprocessing import Pool

from test_cfg import kHost
from common import write_feature_to_file, read_file, statics_one_file

kUrl = kHost + '/faceService/buildFeatureVecByB64'


def build_feature_by_image_task(lines, i, batch_num, output_path):
    headers = {}
    headers['Content-Type'] = 'application/json; charset=UTF-8'

    if batch_num <= 0:
        batch_num = 1

    request_body = {}
    data_list = []
    succeed_count = 0
    succeed_total_time = 0
    failed_count = 0
    failed_total_time = 0
    time_max = 0.0
    time_min = 1000.0

    count = 0
    
    sum_count = len(lines)
    #print 'lines = ', lines
    print 'i: {}, sum_count: {}, batch_num: {}'.format(i, sum_count, batch_num)

    result_file = 'process' + '_' + str(i) + '.txt'
    fp = open(os.path.join(output_path, result_file), 'w')

    for index in range(0, sum_count, batch_num):
        batch_num = min(sum_count-index,batch_num)
        sub_lines = lines[index : (index+batch_num)]

        image_list = []
        label_list = []
        data_list = []
        for line in sub_lines:
            segments = line.strip('\n').strip(' ').split('\t')
            if len(segments) < 3:
                print 'len(segments) = %d' % len(segments)
                continue

            tmp = {}
            try:
                image_str = base64.b64encode(open(segments[0], 'rb').read())
            except Exception as e:
                print str(e)

            tmp['imagebase64'] = image_str
            tmp['guid'] = str(segments[1])
            #tmp['libid'] = str(segments[2])
            tmp['libid'] = '-1'

            label_list.append(segments[1])
            image_list.append(segments[0])
            data_list.append(tmp)

        request_body['data'] = data_list
        request_body['getfeature'] = '1'
        send_num = len(data_list)

            
        try:
            http_session = requests.Session()
            data_req = json.dumps(request_body)
            time_begin = time.time()
            r = http_session.post(kUrl, headers=headers, data=data_req, timeout=50)

            count += send_num
            print '-----%d / %d-----' % (count, len(lines))
            elapse = (time.time() - time_begin) * 1000.0
            if elapse > time_max:
                time_max = elapse
            elif elapse < time_min:
                time_min = elapse

            print 'i = {}, status_code = {}'.format(i, r.status_code)
            if (r.status_code) == 200:
                json_ret = json.loads(r.content)
                #print json_ret
                if json_ret['rtn'] == '000':
                    results = json_ret['result']
                    for j in xrange(len(results)):
                        print '----------------', len(results[j]['feature'])
                        if len(results[j]['feature']) == 1024:
                            succeed_count += 1
                            succeed_total_time += elapse
                            fp.writelines('{}\t{}\n'.format(image_list[j], 'T'))
                            
                            feature_file = image_list[j] + '.feature'
                            write_feature_to_file(results[j]['feature'], feature_file)
                        else:
                            failed_count += 1
                            failed_total_time += elapse
                            fp.writelines('{}\t{}\n'.format(image_list[j], 'F'))
                else:
                    failed_count += send_num
                    failed_total_time += elapse

                    for i in range(send_num):
                        fp.writelines('{}\t{}\n'.format(image_list[i], 'F'))

            else:
                failed_count += send_num
                failed_total_time += elapse

                for i in range(send_num):
                    fp.writelines('{}\t{}\n'.format(image_list[i], 'F'))
            fp.flush()

            http_session.close()
        except Exception as e:
            print str(e)

    if failed_count <= 0:
        rst_content = 'total_time: {}s, total: {}, succeed_count: {}, succeed_aver: {}ms, time_max: {}ms, time_min: {}ms'.format(succeed_total_time / 1000, len(lines), succeed_count, succeed_total_time / succeed_count, time_max, time_min)
        print rst_content
    else:
        failed_aver = failed_total_time / failed_count
        acc_rate = float(succeed_count) / len(lines)
        rst_content = 'total_time: {}s, total: {}, succeed_count: {}, succeed_aver: {}ms, failed_count: {}, failed_aver: {}ms, acc_rate: {}, time_max: {}, time_min: {}'.format((succeed_total_time + failed_total_time) / 1000, len(lines), succeed_count,succeed_total_time / succeed_count, failed_count, failed_aver, acc_rate, time_max, time_min)
        print rst_content
    fp.close()

    print 'process {} test end....'.format(i)


def main(file_path, process_num, batch_num, output_path): 
    lines = read_file(file_path)
    sum_num = len(lines)

    batch = sum_num / process_num
    if batch == 0:
        batch = sum_num
        process_num = 1
    p = Pool(process_num)

    print 'process_num = %d, batch = %d'% (process_num, batch)

    index = 0
    index_end = 0
    time_begin = time.time()
    for i in range(process_num):
        remain = sum_num - index
        """
        if remain < process_num:
            index_end = index + remain
        else:
            index_end = index + batch
        """
        if i < process_num - 1:
            index_end = index + batch
        else:
            index_end = index + remain

        print 'i = {}, index = {}, index_end = {}'.format(i, index, index_end)
        p.apply_async(build_feature_by_image_task, args=(lines[index : index_end], i, batch_num, output_path))
        #index += batch
        index = index_end

    print('Waiting for all subprocesses done...')  

    p.close()
    p.join()

    time_end = time.time()
    elapse = (time_end - time_begin) * 1000.0
    average_time = elapse / len(lines)
    num_every_sec = len(lines) / float(time_end - time_begin)
    num_every_min = num_every_sec * 60
    print 'total time: {}s, num_every_sec: {}, num_every_min: {}\n'.format(time_end - time_begin, num_every_sec, num_every_min)

    fp = open(os.path.join(output_path, 'static_build_feature_result.txt'), 'w')
    fp.write('total time: {}s, num_every_sec: {}, num_every_min: {}\n'.format(time_end - time_begin, num_every_sec, num_every_min))
    succeed_count = 0
    failed_count = 0
    for file in os.listdir(output_path):
        if file.find('process_') != -1:
            ret = statics_one_file(os.path.join(output_path, file), 2, 1)
            succeed_count += ret[0]
            failed_count += ret[1]

    accuracy_rate = float(succeed_count) / (succeed_count + failed_count)
    print 'accuracy_rate = {}'.format(accuracy_rate)
    fp.write('accuracy_rate = {}'.format(accuracy_rate))
    fp.close()
    
    print('All subprocesses done.')



if __name__ == '__main__':
    print 'conturrency ...'

    """
    功能： 并发测试提特征或入库。
    @param1: file_path 每一行包含图片全路径，guid  libid的字段
    @param2: process_num 进程数目
    @param3: batch_num 单次发送图片数目
    @param4：output_path 结果输出路径
    """

    if len(sys.argv) < 5:
        print 'Usage: python concurrency_1vn.py [file_path] [process_num] [batch_num] [output_path]'
        sys.exit()

    file_path = sys.argv[1]

    process_num = int(sys.argv[2])
    assert(process_num > 0)

    batch_num = int(sys.argv[3])

    output_path = sys.argv[4]
    if os.path.exists(output_path):
        shutil.rmtree(output_path)
    os.makedirs(output_path)

    main(file_path, process_num, batch_num, output_path)
