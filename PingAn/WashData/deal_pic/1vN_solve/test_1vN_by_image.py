#coding=utf-8

import os,re,sys,shutil
import requests
import json
import hashlib
import base64
import time
import random
import binascii
import hmac
import sys
import logging
from hashlib import sha1
from sigunate import *
from test_cfg import kHost
import subprocess


kUrl = kHost + '/faceService/searchFace1VN'
delete_kUrl = kHost + '/faceService/delCharactBatch'
kBoundId = 'com.paic.real-estate'

###################1Vn########################
def do_1vN(file_path, libid, top_num):
    request_body = {}

    time_begin = time.time()
    str_timestamp_ms = str(int(time.time() * 1000))
    # str_rand = str(random.randint(0, 2147483647))
    str_signature = request_signature(str_timestamp_ms, kBoundId)
    
    headers = {}
    headers['Content-Type'] = 'application/json; charset=UTF-8'

    image_str = base64.b64encode(open(file_path, 'rb').read())
    request_body['imagebase64'] = image_str
    request_body['libids'] =  libid
    request_body['top'] = top_num 
    
    http_session = requests.Session()
    data_req = json.dumps(request_body)


    r = http_session.post(kUrl, headers=headers, data=data_req)
    if (r.status_code) == 200:

        json_result = json.loads(r.content)
        caculater_similar=0
        for result in json_result['result']:
            #print 'guid = {}, libid = {}, similarity = {}'.format(result['guid'], result['libid'], result['similarity'])
            caculater_similar+=int(result['similarity'])
        caculater_similar=caculater_similar/top_num
        return  caculater_similar  
    else:    
        print 'failed. {}'.format(r.content)
        return 
    http_session.close()
    return 

#################DelPicFromLib###################
def DelPicFromLib(guid,libid,simi_threshold):
    headers = {}
    headers['Content-Type'] = 'application/json; charset=UTF-8'

    request_body = {}
    data_list = []
    tmp = {}
    tmp['guid'] = guid.encode('utf-8')
    tmp['libid'] =libid.encode('utf-8')
    data_list.append(tmp)


    print 'data_list = {}'.format(data_list)
    request_body['data'] = data_list

    http_session = requests.Session()
    data_req = json.dumps(request_body)

    r = http_session.post(delete_kUrl, headers=headers, data=data_req)
    if (r.status_code) == 200:
        print 'content: '
        print r.content
        print json.loads(r.content)
    else:
        print "delete pic error"
    http_session.close()

###################  MAIN    #############
if __name__=='__main__':
    
    if len(sys.argv)<2:
        print "input [file.txt],[libid]"
        sys.exit()

    src_dir=sys.argv[1]
    libid=sys.argv[2]
    top=2
    simi_threshold=90


    os.system('> ./ouput.txt')
    find_pic_star1_command="find "+src_dir+" -name '1*' > ./ouput.txt"
    print find_pic_star1_command
    os.system(find_pic_star1_command)

    file_fd = open("./ouput.txt", "r+")
    file_=open("./result.txt",'w')
    file_array=file_fd.readlines()
    for file in file_array:
        if do_1vN(file[:-1],libid,int(top))<simi_threshold :
            file_.write(file.split('/')[-2]+'\n')


    file_fd.close()
    file_.close()