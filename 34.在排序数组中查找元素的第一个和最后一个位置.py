'''
Author: your name
Date: 1970-01-01 08:00:00
LastEditTime: 2020-09-30 00:06:04
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /Leetcode/Chinese/34.在排序数组中查找元素的第一个和最后一个位置.py
'''
#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
#     def searchRange(self, nums, target):
#         index1 = self.findFirstPosition(nums, target)
#         index2 = self.findLastPosition(nums, target)
#         return [index1, index2]
    
#     def findFirstPosition(self, nums, target):
#         if nums is None or len(nums) == 0: return -1
        
#         start, end = 0, len(nums) - 1

#         while (start + 1 < end):

#             mid = (end - start) // 2 + start

#             if target == nums[mid]:
#                 end = mid
#             elif target < nums[mid]:
#                 end = mid
#             else:
#                 start = mid
        
#         if nums[start] == target: return start
#         if nums[end] == target: return end
#         return -1
    
#     def findLastPosition(self, nums, target):
#         if nums is None or len(nums)==0: return -1
        
#         start, end = 0, len(nums) - 1

#         while (start + 1 < end):

#             mid = (end - start) // 2 + start

#             if target == nums[mid]:
#                 start = mid
#             elif target < nums[mid]:
#                 end = mid
#             else:
#                 start = mid
        
#         if nums[end] == target: return end
#         if nums[start] == target: return start
#         return -1

# sol = Solution()
# print(sol.searchRange([1, 2, 3, 4, 4], 4))

    def searchRange(self, nums, target):
        res = [-1, -1]

        if not nums:
            return res

        left = 0
        right = len(nums) - 1

        while left < right:
            # mid = (left + right) // 2

            mid = (right - left) // 2 + left
            if nums[mid] < target:
                left = mid + 1 
            else:
                right = mid
        if nums[left] != target:
            return res
        res[0] = left
        
        left = 0
        right = len(nums) - 1

        while left < right:
            # mid = (left + right +1) // 2
            mid = (right - left + 1 ) // 2 + left
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid
        res[-1] = right
        return res


sol = Solution()
print(sol.searchRange([5, 7, 7, 8, 8, 10], 10))



# @lc code=end

