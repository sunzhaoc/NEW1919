'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-05-02 10:57:35
FilePath: \Leetcode\Week Competition\Weekly Contest 239\t4.py
'''



class Solution:
    def splitString(self, s: str) -> bool:
        def backTrack(s, idx, path):
            num = int(s[idx])
        res = False
        n = len(s)
        for i in range(n):
            if s[i] != '0':
                s = s[i:]
                break
        
        path = []

            