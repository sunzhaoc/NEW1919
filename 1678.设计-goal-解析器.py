'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 10:08:43
LastEditTime: 2021-04-22 10:12:59
FilePath: \Leetcode\1678.设计-goal-解析器.py
'''
#
# @lc app=leetcode.cn id=1678 lang=python3
#
# [1678] 设计 Goal 解析器
#

# @lc code=start
"""
RESULT: Accept
TIME:     36ms    BEAT: 82.41%    O(n) = 
MEMORY: 14.9MB    BEAT: 21.09%    O(n) = 
USED TIME: 03:03
LAST EDIT TIME: 2021年4月22日10:12:41
Description: 
"""

class Solution:
    def interpret(self, command: str) -> str:
        idx = 0
        res = ""
        while idx < len(command):
            if command[idx] == 'G': 
                res += "G"
                idx += 1
            elif command[idx] == '(' and command[idx + 1] == ')':
                res += "o"
                idx += 2
            else:
                res += "al"
                idx += 4
        return res
            
# @lc code=end

