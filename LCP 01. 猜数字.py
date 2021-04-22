'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:22:37
LastEditTime: 2021-04-22 09:24:31
FilePath: \Leetcode\LCP 01. 猜数字.py
'''

"""
RESULT: Accept
TIME:     40ms    BEAT: 59.83%    O(n) = 
MEMORY: 14.7MB    BEAT: 84.27%    O(n) = 
USED TIME: 01:09
LAST EDIT TIME: 2021年4月22日9:24:18
Description: 
"""

class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        cnt = 0
        for i in range(len(guess)):
            if guess[i] == answer[i]: 
                cnt += 1
        return cnt