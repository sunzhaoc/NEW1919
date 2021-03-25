'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-19 16:45:02
LastEditTime: 2020-11-19 21:39:20
FilePath: \Leetcode\Chinese\55.跳跃游戏.py
'''
#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution:
    def canJump(self, nums):
        if len(nums) == 1:
            return True
        max_step = 1
        for id, val in enumerate(nums):
            if max_step == id + 1 and val == 0:
                return False
            max_step = max(max_step, id + 1 + val)
            if max_step >= len(nums):
                return True
        if max_step < len(nums):
            return False

sol = Solution()
A = sol.canJump([0])
print(A)
# @lc code=end

