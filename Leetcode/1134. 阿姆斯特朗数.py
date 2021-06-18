'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 19:13:53
LastEditTime: 2021-04-22 19:18:55
FilePath: \Leetcode\1134. 阿姆斯特朗数.py
'''

"""
RESULT: Accept
TIME:     40ms    BEAT: 64.47%    O(n) = 
MEMORY: 14.9MB    BEAT: 13.16%    O(n) = 
USED TIME: 03:53
LAST EDIT TIME: 2021年4月22日19:18:42
Description: 
"""

class Solution:
    def isArmstrong(self, n: int) -> bool:
        num = 0
        tmpN = n
        while tmpN:
            tmpN //= 10
            num += 1
        sum = 0
        tmpN = n
        while tmpN:
            sum += pow(tmpN % 10, num)
            tmpN //= 10
        return sum == n
        