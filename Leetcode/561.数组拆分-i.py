'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 20:03:25
LastEditTime: 2021-04-22 20:08:16
FilePath: \Leetcode\561.数组拆分-i.py
'''
#
# @lc app=leetcode.cn id=561 lang=python3
#
# [561] 数组拆分 I
#

# @lc code=start
"""
RESULT: Accept
TIME:     88ms    BEAT: 33.55%    O(n) = 
MEMORY: 16.6MB    BEAT: 36.28%    O(n) = 
USED TIME: 03:14
LAST EDIT TIME: 2021年4月22日20:7:59
Description: 
"""

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        res = 0
        n = 0
        while (n < len(nums)):
            res += nums[n]
            n += 2
        return res

# @lc code=end

