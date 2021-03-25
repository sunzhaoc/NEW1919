'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-03 17:12:45
LastEditTime: 2021-03-03 17:22:42
FilePath: \Leetcode\266.回文排列.py
'''

import collections

class Solution:
    def canPermutePalindrome(self, s):
        dict = collections.defaultdict(int)
        for i in s:
            dict[s] += 1
        cnt = 1
        for key, num in dict.items():
            if num % 2 == 1:
                cnt -= 1
            if cnt < 0: 
                return False
        return True


sol = Solution()
ans = sol.canPermutePalindrome("code")
