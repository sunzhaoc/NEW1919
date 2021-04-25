'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-03-03 15:13:09
LastEditTime: 2021-03-03 15:19:04
FilePath: \Leetcode\154.寻找旋转排序数组中的最小值-ii.py
'''
#
# @lc app=leetcode.cn id=154 lang=python3
#
# [154] 寻找旋转排序数组中的最小值 II
#

# @lc code=start


"""
RESULT: Accept
TIME:     36ms    BEAT: 85.06%    O(n) = logn
MEMORY: 15.2MB    BEAT: 33.11%    O(n) = 1
USED TIME: 04:40
LAST EDIT TIME: 2021年3月3日15:19:3
Description: 二分查找。
"""

class Solution:
    def findMin(self, nums: List[int]) -> int:
        L, R = 0, len(nums) - 1
        ans = 99999

        while (L <= R):
            mid = (R - L) // 2 + L
            
            if nums[L] == nums[mid]:
                ans = min(ans, nums[mid])
                L += 1
                continue
            
            if nums[L] <= nums[mid]:
                ans = min(ans, nums[L])
                L = mid + 1
            else:
                ans = min(ans, nums[min])
                R = mid - 1

        return ans
# @lc code=end

