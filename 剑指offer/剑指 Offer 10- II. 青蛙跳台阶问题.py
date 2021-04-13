'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-10 16:26:55
LastEditTime: 2020-12-15 20:34:11
FilePath: \Leetcode\剑指 Offer 10- II. 青蛙跳台阶问题.py
'''


"""
RESULT: Accept
TIME:     36ms    BEAT: 82.11%    O(n) = 
MEMORY: 14.8MB    BEAT:  5.05%    O(n) =  
Description: 
"""

class Solution:
    def numWays(self, n):
        a, b = 1, 1
        for _ in range(n):
            a, b = b, a + b
        return a % 1000000007