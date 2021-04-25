'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 14:12:21
LastEditTime: 2021-04-22 14:14:29
FilePath: \Leetcode\1221.分割平衡字符串.py
'''
#
# @lc app=leetcode.cn id=1221 lang=python3
#
# [1221] 分割平衡字符串
#

# @lc code=start
"""
RESULT: Accept
TIME:     48ms    BEAT: 17.42%    O(n) = 
MEMORY: 14.7MB    BEAT: 90.58%    O(n) = 
USED TIME: 01:26
LAST EDIT TIME: 2021年4月22日14:14:12
Description: 
"""

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        l, r = 0, 0
        cnt = 0
        for ch in s:
            if ch == 'R': r += 1
            else: l += 1
            if l == r: cnt += 1
        return cnt
# @lc code=end

