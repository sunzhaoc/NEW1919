'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-03 22:45:32
LastEditTime: 2020-12-03 22:48:19
FilePath: \Leetcode\剑指 Offer 53 - II. 0～n-1中缺失的数字.py
'''

"""
RESULT: Accept
TIME: 40ms BEAT: 88.02%
MEMORY: 14.5MB BEAT: 28.29%
Description: 二分查找
"""
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        
        while l < r:
            mid = (r - l) // 2 + l;

            if nums[mid] == mid:
                l = mid + 1
            else:
                r = mid
        
        if nums[l] == l:
            return l + 1
        else:
            return l