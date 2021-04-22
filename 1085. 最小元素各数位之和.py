'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 19:19:25
LastEditTime: 2021-04-22 19:22:21
FilePath: \Leetcode\1085. 最小元素各数位之和.py
'''

"""
RESULT: Accept
TIME:   44ms    BEAT: 25.56%    O(n) = 
MEMORY: 15MB    BEAT:  5.56%    O(n) = 
USED TIME: 02:11
LAST EDIT TIME: 2021年4月22日19:22:8
Description: 
"""

class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        minNum = min(A)
        sum = 0
        while minNum:
            sum += minNum % 10
            minNum //= 10
        return -(sum % 2) + 1