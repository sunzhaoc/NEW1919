'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 10:53:32
LastEditTime: 2021-04-22 10:55:17
FilePath: \Leetcode\1342.将数字变成-0-的操作次数.py
'''
#
# @lc app=leetcode.cn id=1342 lang=python3
#
# [1342] 将数字变成 0 的操作次数
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 63.13%    O(n) = 
MEMORY: 13.9MB    BEAT: 10.12%    O(n) = 
USED TIME: 00:56
LAST EDIT TIME: 2021年4月22日10:55:1
Description: 
"""

class Solution:
    def numberOfSteps(self, num: int) -> int:
        cnt = 0
        while num:
            if num % 2 == 0: num /= 2
            else: num -= 1
            cnt += 1
        return cnt
# @lc code=end

