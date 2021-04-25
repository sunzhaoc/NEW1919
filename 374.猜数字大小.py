'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 20:58:21
FilePath: /Leetcode/Chinese/374.猜数字大小.py
'''
#
# @lc app=leetcode.cn id=374 lang=python3
#
# [374] 猜数字大小
#

# @lc code=start
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n):
        l, r = 1, n
        while l < r:
            mid = (r - l) // 2 + l
            if guess(mid) == 0:
                return mid
            elif guess(mid) == -1:
                r = mid
            else:
                l = mid + 1
        return l


# @lc code=end

