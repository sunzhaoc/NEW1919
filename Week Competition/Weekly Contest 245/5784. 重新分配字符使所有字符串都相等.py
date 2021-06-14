'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2021-06-13 12:50:26
LastEditTime: 2021-06-13 12:55:48
FilePath: \Leetcode\Week Competition\Weekly Contest 245\5784. 重新分配字符使所有字符串都相等.py
'''

from typing import DefaultDict


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n = len(words)
        dic = DefaultDict(int)
        for word in words:
            for ch in word:
                dic[ch] += 1

        for id, val in dict.items():
            if val % n != 0: return False
        
        return True