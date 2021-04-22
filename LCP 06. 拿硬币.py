'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:27:22
LastEditTime: 2021-04-22 09:29:26
FilePath: \Leetcode\LCP 06. 拿硬币.py
'''

"""
RESULT: Accept
TIME:     40ms    BEAT: 58.83%    O(n) = 
MEMORY: 14.9MB    BEAT: 40.15%    O(n) = 
USED TIME: 01:30
LAST EDIT TIME: 2021年4月22日9:29:11
Description: 
"""

class Solution:
    def minCount(self, coins: List[int]) -> int:
        cnt = 0
        for coin in coins:
            cnt += (coin + 2 - 1) // 2
        return cnt