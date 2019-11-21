import requests
from bs4 import BeautifulSoup

def get_url(titlt,charter):
	url2='https://www.zhaishuyuan.com/chapter/{}/{}'.format(str(title),str(charter))
	return url2

headers= {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}
print("请输入要下载小说编号:")
title=input()
print("请输入章节编号:")
charter=input()
i=0
file=open('D:\\项目\\PythonApplication1\\小说_远东之虎.txt','a')
while(i<1000):
	url=get_url(str(title),str(int(charter)+i))
	page=requests.get(url,headers=headers)
	#print(page.encoding)
	#print(page.apparent_encoding)
	try:
		page.encoding='gbk'
		soup=BeautifulSoup(page.text,'html.parser')
		texs=soup.find('div',id='content')
		i=i+1
		file.write("               第"+str(i)+"章"+'\n')
		for tex in texs.find_all('p'):
			file.write("    "+tex.text+'\n')
		print("第"+str(i)+"章爬取成功！")
	except UnicodeError:
		print("很不幸的告诉您，第"+str(i)+"章爬取失败！")
		#i=i+1
file.close()
