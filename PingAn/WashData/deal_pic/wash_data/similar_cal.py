#coding=utf-8

import os, sys
import numpy as np
"""
def cal_similarity(input_image_path_file, similarity_result_file, idx_start, idx_end):
    path_list = open(input_image_path_file, 'r').readlines()

    similar_cal_txt = open(similarity_result_file, 'w')

    for idx in range(idx_start, len(path_list)):
        if(idx > idx_end):
            break
        line_base = path_list[idx].strip()
        line_base = line_base.split('\t')[0]
        base_name = line_base.split('/')[-2]
        if(os.path.exists(line_base+'.feature') == False):
            continue
        feature_base_txt = open(line_base+'.feature', 'r').readlines()[0]
        feature_base_np = np.array(feature_base_txt[1:len(feature_base_txt)-1].split(', '))
        #feature_base_txt.close()
        print(len(feature_base_np))
        for idy in range(idx+1, len(path_list)):
            line_test = path_list[idy].strip()
            line_test = line_test.split('\t')[0]
            test_name = line_test.split('/')[-2]
            if(base_name != test_name):
                    continue
            if(os.path.exists(line_test+'.feature') == False):
                continue
            feature_test_txt = open(line_test+'.feature', 'r').readlines()[0]
            feature_test_np = np.array(feature_test_txt[1:len(feature_test_txt)-1].split(', '))
            #feature_test_txt.close()
            #sim_score = np.dot(feature_base_np, feature_test_np)
            sim_score = 0.0
            for idz in range(len(feature_base_np)):
                sim_score += (float(feature_base_np[idz])*float(feature_test_np[idz]))
            print(line_base, line_test, sim_score)
            similar_cal_txt.write(line_base+'\t'+line_test+'\t'+str(sim_score)+'\n')

    similar_cal_txt.close()



if __name__ == '__main__':
    if len(sys.argv) < 5:
        print 'Usage: python similar_cal.py [input_image_path_file] [similarity_result_file] [idx_start] [idx_end]'
        sys.exit()

    input_image_path_file = sys.argv[1]
    similarity_result_file = sys.argv[2]
    idx_start = int(sys.argv[3])
    idx_end = int(sys.argv[4])

    cal_similarity(input_image_path_file, similarity_result_file, idx_start, idx_end)

"""
def CompareSimiary(file_list,file_result_similary,line_begin,line_end):


    pic_lists=open(file_list,'r').readlines()
    similar_cal_txt=open(file_result_similary,'w')

    flow_dir=pic_lists[0].split('\t')[1]
    flow_pic_path=pic_lists[0].split('\t')[0]

    for pic in pic_lists:
        pic_dir_name=pic.split('\t')[1]
        if flow_dir==pic_dir_name:
            continue

        pic_name=flow_pic_path.split('/')[-1]            
        pic_dir_path=flow_pic_path[:0-(len(pic_name)+1)]
        

        same_dir_files=os.listdir(pic_dir_path)

        base_pic=""
        for file in same_dir_files:
            if file[:1]=='1' and file[-7:]!="feature" :
                base_pic=file
                break
        
        if base_pic=="":
            continue
        base_pic=pic_dir_path+'/'+base_pic

        feature_base_txt = open(base_pic+'.feature', 'r').readlines()[0]
        feature_base_np = np.array(feature_base_txt[1:len(feature_base_txt)-1].split(', '))

        for file in same_dir_files:
            if file[-7:]=="feature":
                continue 
            
            test_pic=pic_dir_path+'/'+file           
            feature_test_txt = open(test_pic+'.feature', 'r').readlines()[0]
            feature_test_np = np.array(feature_test_txt[1:len(feature_test_txt)-1].split(', '))
            
            sim_score = 0.0
            for idz in range(len(feature_base_np)):
                sim_score += (float(feature_base_np[idz])*float(feature_test_np[idz]))

            print(base_pic, test_pic, sim_score)
            similar_cal_txt.write(base_pic+'\t'+test_pic+'\t'+str(sim_score)+'\n')

        flow_dir=pic.split('\t')[1]
        flow_pic_path=pic.split('\t')[0]


    similar_cal_txt.close()



if __name__=='__main__':
    if len(sys.argv)<4:
        print "input **[file_list,file_result_similary,line_begin,line_end]"
        sys.exit()

    file_list=sys.argv[1]
    file_result_similary=sys.argv[2]
    line_begin=sys.argv[3]
    line_end=sys.argv[4]
    CompareSimiary(file_list,file_result_similary,line_begin,line_end)





