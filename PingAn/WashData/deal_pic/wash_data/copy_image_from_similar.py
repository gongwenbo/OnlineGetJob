#coding=utf-8
import os, sys
import numpy as np
import shutil

nice_path_alpha = '/disk3/jiaojing-washed-v2/downloadcar-wash/alpha/'
nice_path_beta = '/disk3/jiaojing-washed-v2/downloadcar-wash/beta/'
line_list = open('./jiaojing_11w_similar_cal_27w.txt', 'r').readlines()
same_name = 0
nice_file_num = 0
for idx in range(len(line_list)):
        if(same_name > 0):
                same_name -= 1
                continue
        line = line_list[idx].strip()
        data_base = line.split('\t')
        max_score = float(data_base[2])
        file_data = data_base[0].split('/')[7]
        print file_data
        #file_data = file_data.split('-')[1]
        if(len(file_data) > 20):
            continue
        print(file_data)
        for idy in range(idx+1, len(line_list)):
                line = line_list[idy].strip()
                data_test = line.split('\t')
                if(data_base[0].split('/')[7] != data_test[0].split('/')[7]):
                        continue
                if(max_score < float(data_test[2])):
                        max_score = float(data_test[2])
                        data_base = data_test

                same_name += 1

        if(max_score > 0.5):
                nice_file_num += 1
                file_data = data_base[0].split('/')
                new_path = os.path.join(nice_path_alpha, file_data[7])
                if(os.path.exists(new_path) == False):
                    os.makedirs(new_path)
                shutil.copy(data_base[0], os.path.join(nice_path_alpha, file_data[7]))
                file_data = data_base[1].split('/')
                new_path = os.path.join(nice_path_beta, file_data[7])
                if(os.path.exists(new_path) == False):
                    os.makedirs(new_path)
                shutil.copy(data_base[1], os.path.join(nice_path_beta, file_data[7]))

        print('nice_file_num:', nice_file_num)
