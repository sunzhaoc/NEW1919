'''
Description: 
Version: 1.0
Autor: Vicro
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 20:48:54
FilePath: /Leetcode/Chinese/367.有效的完全平方数.py
'''
#
# @lc app=leetcode.cn id=367 lang=python3
#
# [367] 有效的完全平方数
#

# @lc code=start
"""
01: Binary Search
"""
class Solution:
    def isPerfectSquare(self, num):
        l, r = 0, num
        while l < r:
            mid = (r - l) // 2 + l
            
            if mid * mid == num:
                return True
            elif mid * mid < num:
                l = mid + 1
            else:
                r = mid
        if l*l == num:
            return True
        else:
            return False


"""
02: Newton's Method
"""
class Solution:
    def isPerfectSquare(self, num):
        x = num
        while x * x > num:
            x = ((x * x) + num) // (2 * x) # Python 使用 float类型会超时
        if x * x == num:
            return True
        else:
            return False

# @lc code=end

