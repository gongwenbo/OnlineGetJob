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
import numpy as np
from hashlib import sha1
import pprint
from sigunate import *

from test_cfg import kHost
kUrl = kHost + '/faceService/buildFeatureVecByB64'

def add_feature_by_image(libid, guid, file_path):
    headers = {}
    headers['Content-Type'] = 'application/json; charset=UTF-8'

    request_body = {}
    data_list = []

    tmp = {}
    tmp['libid'] = libid
    tmp['guid'] = guid
    #tmp['libid'] = '19'
    image_str = base64.b64encode(open(file_path, 'rb').read())
    tmp['imagebase64'] = image_str

    data_list.append(tmp)
    request_body['data'] = data_list
    data_req = json.dumps(request_body)
    
    http_session = requests.Session()
    r = http_session.post(kUrl, headers=headers, data=data_req)
    if (r.status_code) == 200:
        json_result = json.loads(r.content)
        return json_result
    http_session.close()

    return 

def you():
	print "you"

if __name__ == '__main__':

    if len(sys.argv)<2 :
    	print "input your [pic_directory] and [lib]"
    	sys.exit()
    pic_src=sys.argv[1]
    libid=sys.argv[2]

    os.system('> ./ouput.txt')
    find_src_pic_comd="find "+pic_src+" -name '1*' > ./ouput.txt"
    os.system(find_src_pic_comd)
    pics=open("./ouput.txt",'r').readlines()

    for pic in pics:
    	guid=pic.split('/')[-1]
    	add_feature_by_image(libid,guid,pic[:-1])

		




    


