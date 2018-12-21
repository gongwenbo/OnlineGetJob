#coding=utf-8
import os, sys
import shutil
import multiprocessing
import time

"""
文件夹去重
"""

def main(single_image_folder, multi_image_folder):
	print 'begin...'
	for multi_sdir in os.listdir(multi_image_folder):
		for single_sdir in os.listdir(single_image_folder):
			if single_sdir == multi_sdir:
				shutil.rmtree(os.path.join(single_image_folder, single_sdir))
				break

	print 'end...'


if __name__ == '__main__':
	if len(sys.argv) < 3:
		print 'Usage: python unique_folder.py [single_image_folder] [multi_image_folder]'
		sys.exit()


	single_image_folder = sys.argv[1]
	multi_image_folder = sys.argv[2]

	main(single_image_folder, multi_image_folder)
