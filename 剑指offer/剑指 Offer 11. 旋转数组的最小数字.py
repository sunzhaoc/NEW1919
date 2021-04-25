'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-03 20:26:09
LastEditTime: 2020-12-03 21:01:34
FilePath: \Leetcode\剑指 Offer 11. 旋转数组的最小数字.py
'''

"""
RESULT: Accept
TIME: 40ms BEAT: 72%
MEMORY: 13.7MB BEAT: 24%
Description: 二分查找
"""
class Solution:
    def minArray(self, numbers):
        l, r = 0, len(numbers) - 1
        
        while l < r:
            mid = (r - l) // 2 + l

            if numbers[mid] < numbers[r]:
                r = mid 
            elif numbers[mid] > numbers[r]:
                l = mid + 1
            else:
                r -= 1
                
        return numbers[l]

sol = Solution()
A = sol.minArray([1, 3, 3])
print(A)
        