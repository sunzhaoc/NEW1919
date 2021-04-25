'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 20:11:18
FilePath: /Leetcode/Chinese/278.第一个错误的版本.py
'''
#
# @lc app=leetcode.cn id=278 lang=python3
#
# [278] 第一个错误的版本
#

# @lc code=start
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l < r: 
            mid = (r - l) // 2 + l
            if isBadVersion(mid) == True:
                r = mid
            else:
                l = mid + 1
        return r
                

# @lc code=end

