'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-19 16:59:19
LastEditTime: 2021-04-19 17:11:57
FilePath: \Leetcode\程序员面试金典\面试题 05.07. 配对交换.py
'''

"""
RESULT: Accept
TIME:     20ms    BEAT: 100.00%    O(n) = 1
MEMORY: 14.7MB    BEAT:  82.39%    O(n) = 1
USED TIME: 11:44
LAST EDIT TIME: 2021年4月19日17:11:41
Description: 
"""

class Solution:
    def exchangeBits(self, num: int) -> int:
        odd = num & 0x55555555
        even = num & 0xaaaaaaaa

        odd <<= 1
        even >>= 1

        return even + odd