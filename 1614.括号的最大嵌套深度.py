'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 10:37:37
LastEditTime: 2021-04-22 10:40:24
FilePath: \Leetcode\1614.括号的最大嵌套深度.py
'''
#
# @lc app=leetcode.cn id=1614 lang=python3
#
# [1614] 括号的最大嵌套深度
#

# @lc code=start
"""
RESULT: Accept
TIME:   52ms    BEAT: 7.63%    O(n) = 
MEMORY: 15MB    BEAT: 8.17%    O(n) = 
USED TIME: 02:10
LAST EDIT TIME: 2021年4月22日10:40:9
Description: 
"""

class Solution:
    def maxDepth(self, s: str) -> int:
        res = 0
        curL = 0
        for ch in s:
            if ch == '(':
                curL += 1
                res = max(res, curL)
            elif ch == ')':
                curL -= 1
        return res


        
# @lc code=end

