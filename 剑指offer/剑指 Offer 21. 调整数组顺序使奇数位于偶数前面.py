'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-24 11:16:26
LastEditTime: 2020-12-24 13:04:57
FilePath: \Leetcode\剑指 Offer 21. 调整数组顺序使奇数位于偶数前面.py
'''



"""
RESULT: Accept
TIME:     52ms    BEAT: 85.11%    O(n) = 
MEMORY: 18.8MB    BEAT:  6.84%    O(n) = 
Description: 快慢双指针。
"""

class Solution:
    def exchange(self, nums):
        low, fast = 0, 0
        while fast < len(nums):
            if nums[fast] % 2 == 1:
                nums[fast], nums[low] = nums[low], nums[fast]
                low += 1
            fast += 1
        return nums

        
"""
RESULT: Accept
TIME:     84ms    BEAT: 8.51%    O(n) = 
MEMORY: 18.7MB    BEAT: 9.65%    O(n) = 
Description: 本题要求在原数组中更改，故不能开辟新空间。使用首尾双指针。
"""

# class Solution:
#     def exchange(self, nums):
        # left, right = 0, len(nums) - 1
        # while left < right:
        #     if nums[left] % 2 == 0 and nums[right] % 2 == 1:
        #         nums[left], nums[right] = nums[right], nums[left]
        #     if nums[left] % 2 == 1: left += 1
        #     if nums[right] % 2 == 0: right -= 1
        # return nums


sol = Solution()
ans = sol.exchange([1, 2, 3, 4])
print(ans)