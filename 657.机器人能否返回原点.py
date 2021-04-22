'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 15:57:52
LastEditTime: 2021-04-22 16:00:29
FilePath: \Leetcode\657.机器人能否返回原点.py
'''
#
# @lc app=leetcode.cn id=657 lang=python3
#
# [657] 机器人能否返回原点
#

# @lc code=start
"""
RESULT: Accept
TIME:     72ms    BEAT: 41.56%    O(n) = 
MEMORY: 15.1MB    BEAT: 12.22%    O(n) = 
USED TIME: 00:53
LAST EDIT TIME: 2021年4月22日16:0:18
Description: 
"""

import collections
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        map = collections.Counter(moves)
        if map['U'] == map['D'] and map['L'] == map['R']: return True
        return False

# @lc code=end

