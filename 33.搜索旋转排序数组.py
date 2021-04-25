'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-13 22:51:06
FilePath: /Leetcode/Chinese/33.搜索旋转排序数组.py
'''
#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#

# @lc code=start
class Solution:
    def search(self, nums, target):
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (r - l) // 2 + l
            if nums[mid] == target:
                return mid
            
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] <= target <= nums[len(nums) - 1]:
                    l = mid + 1
                else:
                    r = mid - 1
        if nums[r] != target:
            return -1
        else:
            return r


sol = Solution()
print(sol.search([4,5,6,7,0,1,2], 3))
# @lc code=end

