'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:24:55
LastEditTime: 2021-04-22 09:26:45
FilePath: \Leetcode\1486.数组异或操作.py
'''
#
# @lc app=leetcode.cn id=1486 lang=python3
#
# [1486] 数组异或操作
#

# @lc code=start
"""
RESULT: Accept
TIME:     32ms    BEAT: 95.44%    O(n) = 
MEMORY: 14.9MB    BEAT: 23.63%    O(n) = 
USED TIME: 01:14
LAST EDIT TIME: 2021年4月22日9:26:30
Description: 
"""

class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        res = 0
        for i in range(n):
            res ^= start + 2 * i
        return res
# @lc code=end

