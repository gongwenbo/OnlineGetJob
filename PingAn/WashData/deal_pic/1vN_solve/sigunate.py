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
from hashlib import sha1
from hashlib import sha256

sys.path.append("..")
from test_cfg import kHost

reload(sys)
sys.setdefaultencoding('utf8')  # @UndefinedVariable

boundinfo={"6222980101038034":"1234567890ABCDEFG",
  "com.paic.JHGT-FRS":"E11265567924412E9B82F8C0B49ED943",
  "com.paic.real-estate":"2DFA209C10FD427992E475A83B49E19D"
}
  

def request_signature(timestamp, boundid):
    encode_content = timestamp
    key = str("bioauth" + boundinfo[boundid]).encode('utf-8')
    my_hmac = hmac.new(key, encode_content, sha256)
    return my_hmac.hexdigest().upper()

def response_signature(timestamp, none, boundid, info):
  encode_content = str(timestamp) + str(none)
  encode_content = encode_content.encode('utf8')

  if not boundinfo.has_key(boundid):
    return 'no_such_boundid_key'
  key = str("bioauth" + boundinfo[boundid] + info).encode('utf8')
  my_hmac = hmac.new(key, encode_content, sha256)
  decode_content = my_hmac.hexdigest()
  return decode_content

def request_token(image, boundid):
    key = str("bioauth" + boundinfo[boundid]).encode('utf8')
    my_hmac = hmac.new(key, image, sha256)
    return my_hmac.hexdigest().upper()
