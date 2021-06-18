'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 11:11:52
LastEditTime: 2021-04-22 12:03:58
FilePath: \Leetcode\1662.检查两个字符串数组是否相等.py
'''
#
# @lc app=leetcode.cn id=1662 lang=python3
#
# [1662] 检查两个字符串数组是否相等
#

# @lc code=start
"""
RESULT: Accept
TIME:   28ms    BEAT: 98.97%    O(n) = 
MEMORY: 15MB    BEAT: 11.55%    O(n) = 
USED TIME: 01:20
LAST EDIT TIME: 2021年4月22日12:3:46
Description: 
"""

class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        for i in range(1, len(word1)):
            word1[0] += word1[i]
        for i in range(1, len(word2)):
            word2[0] += word2[i]
        return word1[0] == word2[0]
        
# @lc code=end

