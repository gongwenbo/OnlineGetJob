#coding=utf-8
import os,re,sys,shutil
import requests
import json
import base64
import time
import random


sys.path.append("..")

from test_cfg import kHost

kUrl = kHost + '/faceService/imageQuality'
#kBoundId = 'com.paic.real-estate'
kBoundId = 'com.paic.real-estate'

def read_file(filename):
    with open(filename, 'r') as fp:
        lines = fp.readlines()
        return lines

def main(input_file, output_file):
    fp = open(output_file, 'w')

    lines = read_file(input_file)
    count = 0
    total = len(lines)
    for line in lines:
        line = line.strip().strip('\n')
        if not line:
            continue

        url = kUrl
        headers = {'content-type': 'application/json; charset=UTF-8'}

        imagebase64 = None
        image = line
        with open(image,"rb") as f:
            # b64encode是编码，b64decode是解码
            imagebase64 = base64.b64encode(f.read())
            # base64.b64decode(base64data)

        payload = {
            'imagebase64': imagebase64
        }

        r = requests.post(url, data=json.dumps(payload), headers=headers)
        count += 1
        print '------{}  /  {}-------'.format(count, total)
        #print(r.text)
        result = json.loads(r.text)
        if result['rtn'] == '000':

            fp.write('{}\t{}\t{}\n'.format(image, result['quality'], json.dumps(result['rect'])))
        else:
            print ' {} ,failed'.format(result['rtn'])

    fp.close()
    print 'end ....'


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print 'Usage: python test_imageQuality.py [input_file] [output_file]'
        sys.exit()

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    main(input_file, output_file)
