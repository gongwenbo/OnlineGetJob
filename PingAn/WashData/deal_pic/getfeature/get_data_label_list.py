#coding=utf-8

import re
import os
import sys
import shutil

"""
"""

def main(data_path, filename, libid):
    print 'get data label list begin---------'

    dir_list = os.listdir(data_path)

    fp = open(filename, 'w')
    for sdir in dir_list:
        dst_path = os.path.join(data_path, sdir)
        if not os.path.isdir(dst_path):
            continue
        images = os.listdir(dst_path)
        for image in  os.listdir(dst_path):
            # 文件夹下是普通文件
            if not os.path.isdir(os.path.join(dst_path, image)):
                if not (image.endswith('.jpg') or image.endswith('.jpeg') or image.endswith('.JPEG') or image.endswith('JPG')):
                    continue
                dst_file = os.path.join(dst_path, image)
                fp.write('%s\t%s\t%d\n' % (dst_file, sdir, libid))
                fp.flush()

                # 制造数据
                """
                for i in range(460):
                    fp.write('%s\t%s\t%d\n' % (dst_file, sdir, libid))
                    fp.flush()
                """
            else:
                sub_dst_path = os.path.join(dst_path, image)
                for sub_img in os.listdir(sub_dst_path):
                    if not (sub_img.endswith('.jpg') or sub_img.endswith('.jpeg') or sub_img.endswith('.JPEG') or sub_img.endswith('JPG')):
                        continue
                    dst_file = os.path.join(sub_dst_path, sub_img)
                    fp.write('%s\t%s\t%d\n' % (dst_file, image, libid))
                    fp.flush()
                    
            # 只取一张图片
            #break
    fp.close()
    print 'get data label list end-----------'




if __name__ == '__main__':
    if len(sys.argv) < 4:
        print 'Usage: python get_data_label_list.py [data_dir] [filename] [libid]'
        sys.exit()

    data_path = sys.argv[1]
    filename = sys.argv[2]
    libid = int(sys.argv[3])


    main(data_path, filename, libid)
