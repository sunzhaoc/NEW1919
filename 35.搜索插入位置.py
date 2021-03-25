'''
Description: 
Version: 1.0
Autor: Vicro
Date: 1970-01-01 08:00:00
LastEditTime: 2020-09-29 23:20:03
FilePath: /Leetcode/Chinese/35.搜索插入位置.py
'''

#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    def searchInsert(self, nums, target):
        if len(nums) == 0:
            return 0
        if nums[0] > target:
            return 0
        if nums[-1] < target:
            return len(nums)
        
        left, right = 0, len(nums) - 1
        while left<right:
            mid = (right - left) // 2 + left
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left

sol = Solution()
print(sol.searchInsert([1, 3, 5, 6], 2))



# @lc code=end

