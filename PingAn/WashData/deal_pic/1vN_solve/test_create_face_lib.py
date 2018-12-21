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
from hashlib import sha1
from sigunate import *

sys.path.append("..")

from test_cfg import kHost

kUrl = kHost + '/faceService/createFaceLib'
#kBoundId = 'com.paic.real-estate'
kBoundId = 'com.paic.real-estate'

def main(libid):
    url = kUrl
    headers = {'content-type': 'application/json; charset=UTF-8'}
    libid = str(libid)
    payload = {
        'libid': libid,
        'libname': "{}号人像库".format(libid),
        'desc': '存放人像图片',
        'creatorid': '654321'
    }

    r = requests.post(url, data=json.dumps(payload), headers=headers)
    json_result = json.loads(r.text)
    print json_result['message'].encode('utf-8')
    print json_result['rtn']
    #print(r.text)


if __name__ == '__main__':
    print 'this is entry.'
    if len(sys.argv) < 2:
        print 'Usage: python test_remove_face_lib.py [libid]'
        sys.exit()

    libid = sys.argv[1]
    main(libid)
