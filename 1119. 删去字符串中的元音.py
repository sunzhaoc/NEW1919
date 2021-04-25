'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 08:41:16
LastEditTime: 2021-04-22 08:43:31
FilePath: \Leetcode\1119. 删去字符串中的元音.py
'''

"""
RESULT: Accept
TIME:   36ms    BEAT: 80.36%    O(n) = 
MEMORY: 15MB    BEAT: 12.00%    O(n) = 
USED TIME: 01:18 
LAST EDIT TIME: 2021年4月22日8:43:16
Description: 
"""

class Solution:
    def removeVowels(self, s: str) -> str:
        res = ""
        for x in s:
            if x != 'a' and x != 'e' and x != 'i' and x != 'o' and x != 'u':
                res += x
        return res