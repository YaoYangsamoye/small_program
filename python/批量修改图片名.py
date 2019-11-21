#批量修改图片名称

import os
import re
import sys
path="H:\图片\手机桌面"

def renameall(path):
    filelist=os.listdir(path)   # os.listdir()用于返回指定文件夹包含的文件或者文件夹名列表
    print("修改前："+str(filelist)) 


    #必须更改工作目录，否则会找不到文件
    currentpath=os.getcwd()      # os.getcwd()用于返回当前工作目录
    os.chdir(path)               # os.chdir()用于改变当前工作目录到指定目录



    num=1
    for filename in filelist:
        pat=".+\.(jpg|jpeg|JPG|png)"
        pattern=re.findall(pat,filename)
        print('pattern[',str(num),']:',pattern)
        print('num：',num,'filename:',filename)
        os.rename(filename,('手机桌面_'+str(num)+'.'+pattern[0]))   # 这里为什么是pattern[0]？
        num = num+1 
    print("---------------------------------------------------")
    #os.chdir(currentpath)        #改回程序运行前的工作目录
    sys.stdin.flush()            #刷新
    print("修改后："+str(os.listdir(path)))        #输出修改后文件夹中包含的文件
 
renameall(path)
