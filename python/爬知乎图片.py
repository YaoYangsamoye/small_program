from urllib
import request
from bs4 import BeautifulSoup 
import time 
import re
url='https://www.zhihu.com/question/26037846' 
headers= {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

page=request.Request(url,headers=headers)
page_img=request.urlopen(page).read().decode('utf-8')
soup=BeautifulSoup(page_img,'html.parser')

links=soup.find_all('img',"origin_image zh-lightbox-thumb",src=re.compile(r'.jpg$'))

local_path = r'E:\结果\picture'

for link in links:
   print(link.attrs['src'])
request.urlretrieve(link.attrs['src'], local_path+r'%s.jpg' % time.time())