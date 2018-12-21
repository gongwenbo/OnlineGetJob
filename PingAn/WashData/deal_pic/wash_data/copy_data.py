#coding: utf-8
import os,sys
import shutil 

def DeleteFromThtread(file_path,thread_num):

	with open(file_path,"r+") as fd:
		lines=fd.readlines()
		fd.seek(0)
		for line in lines:
			#print line.split('\t')[0]

			if line.split('\t')[2]>thread_num :
				#print line.split('\t')[2] , " ",thread_num
				fd.write(line)	
		fd.truncate()	



def SeletctData(file_path,target_dir_path):



	with open(file_path,'r') as fd:
		lines=fd.readlines()
		for line in lines:
			line_element=line.split('\t')
			directory_first=target_dir_path+'/'+line_element[0].split('/')[-2]
			directory_second=target_dir_path+'/'+line_element[1].split('/')[-2]

			print directory_second,"* ",line_element[0]
			if not os.path.exists(directory_first):
				os.makedirs(directory_first)
			#copyfile(line_element[0], directory_first)
			src=line_element[0]
			dst=directory_first
			shutil.copyfile(src, '%s/%s' % (dst, src.split('/')[-1]))

			if not os.path.exists(directory_second):
				os.makedirs(directory_second) 
			
			src=line_element[1]
			dst=directory_second
			shutil.copyfile(src, '%s/%s' % (dst, src.split('/')[-1]))

			#file_first=line_element[0].split('/')[-1]
			#file_second=line_element[1].split('/')[-1]


def CopyDate(file_path,thread_num,target_dir_path):

	DeleteFromThtread(file_path,thread_num)
	SeletctData(file_path,target_dir_path)
	


if __name__=='__main__':
	if len(sys.argv)<3:
		print "input file_path,thread_num,target_dir_path"
		sys.exit()	

	file_path=sys.argv[1]
	thread_num=sys.argv[2]
	target_dir_path=sys.argv[3]
	CopyDate(file_path,thread_num,target_dir_path)






