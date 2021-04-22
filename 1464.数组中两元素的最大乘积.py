'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 20:42:21
LastEditTime: 2021-04-22 20:46:49
FilePath: \Leetcode\1464.数组中两元素的最大乘积.py
'''
#
# @lc app=leetcode.cn id=1464 lang=python3
#
# [1464] 数组中两元素的最大乘积
#

# @lc code=start
"""
RESULT: Accept
TIME:   52ms    BEAT: 23.44%    O(n) = 
MEMORY: 15MB    BEAT: 13.04%    O(n) = 
USED TIME: 03:07
LAST EDIT TIME: 2021年4月22日20:46:35
Description: 
"""

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums = sorted(nums)
        return (nums[len(nums) - 1] - 1) * (nums[len(nums) - 2] - 1)
# @lc code=end

