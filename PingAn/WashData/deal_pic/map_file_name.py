#coding: utf-8
import multiprocessing
import time
import os,io
import sys
from threading import Thread
import threading
deal_file_nums=0
process_lock = multiprocessing.Lock()

def write_dir_path(txt_name,data ):
    os.system('> txt_name')
    with open(txt_name,"a") as f:
        f.write(data+"\n")

def fetch_dir_path(dirs,txt_name):
    dir=[]
    dir=os.listdir(dirs)
    open(txt_name,'w').close()
    for d in dir:
        #print (dirs+d)
        write_dir_path(txt_name,dirs+'/'+d)

def map_file_id(txt_name,start_line,end_line,ret_file):
    
    f=open(txt_name,'r')
    lines=f.readlines()

    root_dir_name=lines[start_line].split('/')[-2]
    ret_file=root_dir_name+'_'+ret_file
    open(ret_file,'w').close()

    line_len=len(lines)
    if end_line>=line_len:
        end_line=line_len

    with open(ret_file,'w') as ret_file_fd:

        while start_line<=end_line:
                  
            dir_name=lines[start_line].split('/')[-1]
            info="ID: "+dir_name[:-1]+" ### map to num: "+str(start_line)+'\n'

            old_name=lines[start_line][:-1]
            new_name=lines[start_line][:0-len(dir_name)]+str(start_line)
            print "old:",old_name
            print "new:",new_name
            os.rename(old_name,new_name)

            ret_file_fd.write(info)

            start_line+=1
    #print "process PID:",os.getpid()

def MulProcess(func,txt,process_num,map_id_file):
    process_pool=  multiprocessing.Pool(processes = process_num)  
    f=open(txt,'r')
    line_num=len(f.readlines()) 
    deal_with_line=line_num/process_num
    deal_with_line_star=0
    star_line_num=1
    map_id_file_rever=map_id_file
    while star_line_num<=process_num:
        map_id_file+=str(star_line_num)
        process_pool.apply_async(func,(txt,deal_with_line_star\
            ,deal_with_line,map_id_file))
        deal_with_line_star=deal_with_line+1
        deal_with_line+=deal_with_line
        star_line_num+=1
        map_id_file=map_id_file_rever
    process_pool.close()
    process_pool.join()

def loadingBar(count,total,size):
    percent = float(count)/float(total)*100
    sys.stdout.write("\r" + str(int(count)).rjust(3,'0')+"/"+str(int(total)).rjust(3,'0') + ' [' + '='*int(percent/10)*size + ' '*(10-int(percent/10))*size + "]\n")



if __name__=="__main__":

    if len(sys.argv)<2:
        print "input dir,and map_file"
        sys.exit()
    src_dir=sys.argv[1]
    map_id_file=sys.argv[2]
    fetch_dir_path(src_dir,"./txt.txt")    
    MulProcess(map_file_id,"./txt.txt",5,map_id_file)



