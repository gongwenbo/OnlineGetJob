#coding=utf-8


import os
import sys


def write_feature_to_file(feature_list, filename):
    fp = open(filename, 'w')
    fp.write(str(feature_list))
    fp.close()

def read_file(filename):
    lines = None
    with open(filename, 'r') as fp:
        lines = fp.readlines()
    return  lines

def statics_one_file(filename, segments_num, index):
    lines = read_file(filename)

    succeed_count = 0
    failed_count = 0

    for line in lines:
        segments = line.strip().strip('\n').split('\t')
        if len(segments) < segments_num:
            continue
        if segments[index] == 'T':
            succeed_count += 1
        else:
            failed_count += 1
    return (succeed_count, failed_count)