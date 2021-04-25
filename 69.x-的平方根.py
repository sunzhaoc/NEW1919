'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 19:57:15
FilePath: /Leetcode/Chinese/69.x-的平方根.py
'''
#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#

# @lc code=start
"""
01: Binary Search
"""
# class Solution:
#     def mySqrt(self, x):
#         l, r = 0, x
#         while l<r:
#             mid = (r - l + 1) // 2 + l
#             if mid*mid == x:
#                 return mid
#             elif mid*mid <= x:
#                 l = mid
#             else:
#                 r = mid - 1 
#         return l


"""
02: Newton's Method
"""
class Solution:
    def mySqrt(self, x):
        z = x
        while z * z > x:
            z = ((z * z) + x) // (2 * z) # Python 使用 float类型会超时
        return z
        

sol = Solution()
print(sol.mySqrt(99))
# @lc code=end

