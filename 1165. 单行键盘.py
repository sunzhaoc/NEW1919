'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:53:04
LastEditTime: 2021-04-22 09:56:16
FilePath: \Leetcode\1165. 单行键盘.py
'''

"""
RESULT: Accept
TIME:   48ms    BEAT: 95.42%    O(n) = 
MEMORY: 15MB    BEAT: 16.79%    O(n) = 
USED TIME: 02:30
LAST EDIT TIME: 2021年4月22日9:55:57
Description: 
"""

class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        n = len(keyboard)
        chr_idx = defaultdict(int)
        for i in range(n):
            chr_idx[keyboard[i]] = i
        
        res = 0
        pre_pos = 0
        for c in word:
            res += abs(chr_idx[c] - pre_pos)
            pre_pos = chr_idx[c]
        return res