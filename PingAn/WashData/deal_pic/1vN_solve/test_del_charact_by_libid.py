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

from test_cfg import *

kUrl = kHost + '/faceService/delCharactByLibid'
#kBoundId = 'com.paic.real-estate'
kBoundId = 'com.paic.real-estate'

def main(libid):
    headers = {}
    headers['Content-Type'] = 'application/json; charset=UTF-8'

    request_body = {}
    data_list = []

    request_body['libid'] = libid
    request_body['ip'] = ''

    http_session = requests.Session()
    data_req = json.dumps(request_body)

    r = http_session.post(kUrl, headers=headers, data=data_req)
    if (r.status_code) == 200:
        print 'content: '
        print r.content
        print json.loads(r.content)

    http_session.close()




if __name__ == '__main__':
    print 'this is entry.'
    if len(sys.argv) < 2:
        print 'Usage: python del_charact_by_libid.py [libid]'
        sys.exit()

    libid = sys.argv[1]
    main(libid)
