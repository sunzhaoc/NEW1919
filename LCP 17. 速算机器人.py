'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 14:09:46
LastEditTime: 2021-04-22 14:12:02
FilePath: \Leetcode\LCP 17. 速算机器人.py
'''

"""
RESULT: Accept
TIME:     40ms    BEAT: 57.82%    O(n) = 
MEMORY: 14.8MB    BEAT: 74.55%    O(n) = 
USED TIME: 01:39
LAST EDIT TIME: 2021年4月22日14:11:45
Description: 
"""

class Solution:
    def calculate(self, s: str) -> int:
        x, y = 1, 0
        for ch in s:
            if ch == 'A':
                x = 2 * x + y
            else: 
                y = 2 * y + x
        return x + y