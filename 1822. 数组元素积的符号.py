'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 08:36:28
LastEditTime: 2021-04-22 08:40:38
FilePath: \Leetcode\1822. 数组元素积的符号.py
'''

"""
RESULT: Accept
TIME:     44ms    BEAT: 51.60%    O(n) = 
MEMORY: 15.1MB    BEAT:  5.32%    O(n) = 
USED TIME: 03:10
LAST EDIT TIME: 2021年4月22日8:40:24
Description: 
"""

class Solution:
    def arraySign(self, nums: List[int]) -> int:
        cnt = 0
        for x in nums: 
            if x == 0:
                return 0
            if x < 0:
                cnt += 1
        if cnt % 2 == 0:
            return 1
        return -1