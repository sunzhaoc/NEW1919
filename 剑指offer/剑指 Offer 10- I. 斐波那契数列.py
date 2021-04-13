'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-10 16:09:26
LastEditTime: 2020-12-10 16:11:56
FilePath: \Leetcode\剑指 Offer 10- I. 斐波那契数列.py
'''


"""
RESULT: Accept
TIME:     32ms    BEAT: 94.40%    O(n) = n
MEMORY: 13.5MB    BEAT: 15.20%    O(n) = 1
Description: 由于 Python 中整形数字的大小限制 取决计算机的内存 （可理解为无限大），因此可不考虑大数越界问题。
"""

class Solution:
    def fib(self, n):
        a, b = 0, 1
        
        for _ in range(n):
            a, b = b, a + b
        
        return a % 1000000007