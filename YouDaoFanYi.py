#!/usr/local/bin/python3
# -*- coding: utf-8 -*- 
# @Author : Yuze Li
# @Time : 2020-05-13 18:40
""""""
from tkinter import *
from tkinter import messagebox
import requests
from lxml import etree


def getYouDao():
    content = search.get().strip()
    print(content)
    if bool(content) == False:
        messagebox.showinfo('错误','请输入要翻译的内容')
    else:
        print('aa')
        url = 'http://www.youdao.com/w/{}/'.format(content)
        header = {
            "user-agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.163 Safari/537.36"
        }

        req = requests.Session()
        req.headers.update(header)
        response = req.get(url).text
        html = etree.HTML(response)
        result = html.xpath('//div[@class="trans-container"]/ul/li/text()')[0].strip()

        print(result)
        stg.set(result)
# getYouDao()


tk = Tk()
tk.title('中英互译')
tk.geometry('450x100+580+50')
label = Label(tk, text='请输入查询的内容：', fg='red', font=('华文行楷' ,20))
#网格式布局展示
label.grid(row=0, column=0)
#标签
label1 = Label(tk, fg='blue', text='查询到的内容如下：',font=('', 20))
label1.grid(row=1, column=0)
#输入框
search = Entry(tk, width=30)
search.grid(row=0, column=1)
#输出框
stg = StringVar()
show = Entry(tk, width=30, textvariable=stg)
show.grid(row=1, column=1)
#按钮
btn_stat = Button(tk, text='翻译', width=10, command=getYouDao)
btn_stat.grid(row=2, column=0, sticky=W)
#按钮
btn_quit = Button(tk, text='退出', width=10, command=tk.quit)
btn_quit.grid(row=2, column=1, sticky=E)

#信息循环
tk.mainloop()