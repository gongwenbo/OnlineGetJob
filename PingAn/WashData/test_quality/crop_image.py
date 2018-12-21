#coding=utf-8
import os,re,sys
import json
import cv2

def main(input_file):
    with open(input_file, 'r') as fp:
        lines = fp.readlines()

    print 'lines = {}'.format(lines)
    for line in lines:
        segments = line.strip().strip('\n').split('\t')
        if len(segments) < 3:
            print 'segments size is not equal 3'
            continue

        rect = segments[2]
        rect = json.loads(rect)
        image = cv2.imread(segments[0])
        cv2.rectangle(image, (rect['x'], rect['y']), (rect['x']+rect['width'], rect['y']+rect['height']), (255, 0, 0), 3)
        rect_path = './rect_image/'
        if not os.path.exists(rect_path):
            os.makedirs(rect_path)

        filename = os.path.basename(segments[0])
        filename = str(segments[1]) + "_" + filename
        filename = os.path.join(rect_path, filename)
        cv2.imwrite(filename, image)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'Usage: python crop_image.py [input_file]'
        sys.exit()


    input_file = sys.argv[1]

    main(input_file)
