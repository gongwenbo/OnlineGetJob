#coding=utf-8

import os, sys
import numpy as np

def cal_similarity(input_image_path_file, similarity_result_file, idx_start, idx_end):
    path_list = open(input_image_path_file, 'r').readlines()

    similar_cal_txt = open(similarity_result_file, 'w')

    for idx in range(idx_start, len(path_list)):
        if(idx > idx_end):
            break
        line_base = path_list[idx].strip()
        line_base = line_base.split('\t')[0]
        base_name = line_base.split('/')[5]
        if(os.path.exists(line_base+'.feature') == False):
            continue
        feature_base_txt = open(line_base+'.feature', 'r').readlines()[0]
        feature_base_np = np.array(feature_base_txt[1:len(feature_base_txt)-1].split(', '))
        #feature_base_txt.close()
        print(len(feature_base_np))
        for idy in range(idx+1, len(path_list)):
            line_test = path_list[idy].strip()
            line_test = line_test.split('\t')[0]
            test_name = line_test.split('/')[5]
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
