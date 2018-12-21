#coding=utf-8
import os
import re
import sys
import shutil
import json
import base64
import time
import logging
import datetime
import  operator
import timeit
from time import clock
import tornado.httpserver
import tornado.ioloop
import tornado.web
import cv2

from OAConfig import kConfidence
from OAConst import kErrorCodeSystem
from OAError import OAError, OAImageParseError, OASystemError, OAFaceNotFoundError
from OABaseHandler import UrglyDigestHandler
from OAGlobalVar import gRpcExecutor
from OARpcMxnet import rpc_batch_quality_mxnet, rpc_detect_mxnet
from OAImageProcess import resize_img, cv2string


reload(sys)
sys.setdefaultencoding('utf8')  # @UndefinedVariable
    
class api13_image_quality_Handler(UrglyDigestHandler):
    def get_max_face(self, faces, ratio):
        valid_face_num = 0
        rect = {}
        max_x = 0
        max_y = 0
        max_w = 0
        max_h = 0
        max_conf_area = 0

        for face in faces:
            face_rect = face.rects
            if len(face_rect) == 4 and face.confidence >= kConfidence:
                valid_face_num += 1
                cur_conf_area = face_rect[2] * face_rect[3] * face.confidence
                if cur_conf_area > max_conf_area:
                    max_x = face_rect[0]
                    max_y = face_rect[1]
                    max_w = face_rect[2]
                    max_h = face_rect[3]
                    max_conf_area = cur_conf_area
        if max_conf_area > 0:
            rect = {'x': int(max_x / ratio),
                    'y': int(max_y / ratio),
                    'width': int(max_w / ratio),
                    'height': int(max_h / ratio)
                    }

        return (rect, True if valid_face_num > 1 else False)

    def crop_image(self, ori_cv_img, rect):
        img = cv2string(ori_cv_img[rect['y']:rect['y']+rect['height'], rect['x']:rect['x']+rect['width']])
        return img

    @tornado.web.asynchronous
    @tornado.gen.coroutine
    def post(self):
        try:
            logging.info('-----visit quality_Handler::post')
            request_obj = self.parse_json_body_sample(use_image=True)
            image_data = request_obj['image_data']

            datetime_now = datetime.datetime.now()
            process_uid = self.generate_process_uid('bioauthQuality', datetime_now)

            # resize image.
            try:
                dst_data, ori_cv_img, ratio = resize_img(image_data, image_type=2)
            except Exception as e:
                logging.exception('resize_img exception: {}'.format(str(e)))
                raise OAImageParseError()
            
            # 远程调用: 检测人脸
            time_begin = time.time()
            rpc_ret = yield gRpcExecutor.submit(rpc_detect_mxnet, dst_data, process_uid, "")
            elapse = (time.time() - time_begin) * 1000.0
            logging.info('yield rpc_detect_mxnet cost {} ms'.format(elapse))
            if not rpc_ret[0]:
                self.set_status(500)
                raise OASystemError()

            json_rpc_ret = rpc_ret[1]
            if not len(json_rpc_ret.multifaces):
                self.set_status(417)
                raise OAFaceNotFoundError()

            curimage_faces = json_rpc_ret.multifaces[0]
            rect, multi_flag = self.get_max_face(curimage_faces.faces, ratio)
            if len(rect) == 4:
                data = {}
                image = {}
                
                face = self.crop_image(ori_cv_img, rect)

                """
                output = copy.deepcopy(ori_cv_img)
                cv2.rectangle(output, (rect['x'], rect['y']), (rect['x']+rect['width'], rect['y']+rect['height']), (255, 0, 0), 3)
                rect_path = './rect_image/'
                if not os.path.exists(rect_path):
                    os.makedirs(rect_path)

                filename = str(random.random()) + ".jpeg"
                filename = rect_path + filename
                cv2.imwrite(filename, output)"""
                image_list = []
                image_list.append(face)

                # get quality
                rpc_ret = yield gRpcExecutor.submit(rpc_batch_quality_mxnet, image_list, process_uid)
                if not rpc_ret[0]:
                    self.set_status(500)
                    raise OASystemError()

                logging.info('quality score = {}'.format(rpc_ret[1].qualityScore[0]))
                result = {"rtn": "000",
                          "message": "图片质量评分成功",
                          "quality": rpc_ret[1].qualityScore[0] * 100,
                          "agegroup": "保留字段",
                          "rect": rect
                }

                self.set_header("Content-Type", "application/json; charset=UTF-8")
                self.write(json.dumps(result))

            else:
                raise OAFaceNotFoundError()

        except OAError as e:
            result = {
                "rtn": e.errorcode,
                "message": e.errormsg
            }

            self.set_header("Content-Type", "application/json; charset=UTF-8")
            self.write(json.dumps(result))
        except Exception as e:
            self.set_status(500)
            result = {
                "rtn": kErrorCodeSystem,
                "message": 'Face detect failed, system exception'
            }
            logging.info("api13_image_quality_Handler error. reason:{}".format(e))
            self.set_header("Content-Type", "application/json; charset=UTF-8")
            self.write(json.dumps(result))          
