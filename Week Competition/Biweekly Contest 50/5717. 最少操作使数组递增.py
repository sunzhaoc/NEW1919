'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-17 22:14:25
LastEditTime: 2021-04-17 23:15:06
FilePath: \Leetcode\weekcom\Double Week 50\T1.py
'''


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        
        n = len(nums)
        if n == 1: return 0
        cnt = 0

        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                cnt += nums[i - 1] + 1 - nums[i]
                nums[i] = nums[i - 1] + 1
        
        return cnt