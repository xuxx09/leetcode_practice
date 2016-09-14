#!/usr/bin/python
# -*- coding: UTF-8 -*

'''
传言需要写10万行代码才能真正熟手，统计一下你写了多少行代码了
把本代码保存为.py为后缀的文件放在你要统计的文件夹里面，双击运行即可，前提是你的系统装了python
注意要保存为UTF-8编码的文件
by BCCN.静夜思
'''

import os

fileext = ('py', 'js') #设置要统计的文件后缀
rootdir = '.'          #要统计的文件夹，如果统计该统计文件所在的文件夹则不用修改
line_count = 0

def countline(f):
    print f
    with open(f, "r") as f:
        return len(f.readlines())

def walks(path):
    line_count = 0
    for root, dirs, files in os.walk(path):
        for f in files:
            f = os.path.join(root, f)
            line_count = line_count + countline(f)
            print line_count
        for d in dirs:
            d = os.path.join(root, d)
            line_count = line_count + walks(d)
        return line_count

if __name__ == '__main__':
    print u'\n\n\n行数 : %s\n\n\n' % walks('.')
    os.system('pause')
