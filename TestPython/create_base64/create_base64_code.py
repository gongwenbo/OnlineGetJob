#coding=utf-8
import os,re,sys,shutil
#import requests
import json
import hashlib
import base64

def CreateBase64(file_path):
	
	temp_base64_code=base64.b64encode(open(file_path, 'rb').read())
	return temp_base64_code
	


if __name__=='__main__':
	
	print "create base64 code"
	current_path=os.path.abspath('.')  
	dirs = os.listdir( current_path )
	files=[]
	for file in dirs:
		if os.path.splitext(file)[-1][1:] == "jpg":
			file_name_txt=os.path.splitext(file)[0]+".txt"
			file_path=current_path+"/"+file

			#base 64 code
			ret=CreateBase64(file_path)
			data="{},{},".format(ret,file_name_txt)
			with open (file_name_txt,'w') as f:
				f.truncate()
				f.write(data)
				f.write(data)
				f.write(data)
				f.write(data)
				f.write(data)


			#files.append(current_path+"/"+file)
		else:
			continue 




	#file_path=current_path+"/files"
	ret=files
	#ret=CreateBase64(file_path)
	for i in ret:
		print i
	





