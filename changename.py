'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-16 10:33:35
LastEditTime: 2021-04-16 10:45:15
FilePath: \Leetcode\changename.py
'''


import os
path = 'Y:\\2020\\Leetcode'

file_name = os.listdir(path)

for name in file_name:
    if name[-2:] == "py" :
        for s in name:
            if s == '.':
                index_num = name.index(s)
                new_name = name[:index_num + 1] + name[index_num + 2:]
                os.rename(os.path.join(path, name), os.path.join(path, new_name))
                break

a = 1