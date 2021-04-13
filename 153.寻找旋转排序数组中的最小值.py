'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-03 14:57:41
LastEditTime: 2021-03-03 15:18:05
FilePath: \Leetcode\153.寻找旋转排序数组中的最小值.py
'''
#
# @lc app=leetcode.cn id=153 lang=python3
#
# [153] 寻找旋转排序数组中的最小值
#

# @lc code=start


"""
RESULT: Accept
TIME:     32ms    BEAT: 94.22%    O(n) = logn
MEMORY: 15.2MB    BEAT:  8.71%    O(n) = 1
USED TIME: 03:48
LAST EDIT TIME: 2021年3月3日15:2:50
Description: 二分查找。
"""

class Solution:
    def findMin(self, nums: List[int]) -> int:
        L, R = 0, len(nums) - 1
        ans = 5001
        while L <= R:
            mid = (R - L) // 2 + L
            ans = min(ans, nums[mid])

            # 左边有序
            if nums[L] <= nums[mid]:
                ans = min(ans, nums[L])
                L = mid + 1
            # 右边有序
            else:
                ans = min(ans, nums[mid])
                R = mid - 1
        return ans

# @lc code=end

