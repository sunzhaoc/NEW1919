'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 16:11:37
LastEditTime: 2021-04-22 16:18:58
FilePath: \Leetcode\1768. 交替合并字符串.py
'''

"""
RESULT: Accept
TIME:     44ms    BEAT: 34.13%    O(n) = 
MEMORY: 15.1MB    BEAT:  5.29%    O(n) = 
USED TIME: 06:31
LAST EDIT TIME: 2021年4月22日16:18:41
Description: 
"""

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word = ""
        for i in range(max(len(word1), len(word2))):
            if i < len(word1) and i < len(word2):
                word += word1[i] + word2[i]
            elif i >= len(word2):
                word += word1[i: ]
                break
            else:
                word += word2[i: ]
                break
        return word