'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-19 20:50:50
LastEditTime: 2021-04-19 20:52:33
FilePath: \Leetcode\面试题 08.03. 魔术索引.py
'''

"""
RESULT: Accept
TIME:     52ms    BEAT: 20.71%    O(n) = 
MEMORY: 15.4MB    BEAT: 22.75%    O(n) = 
USED TIME: 00:48
LAST EDIT TIME: 2021年4月19日20:52:17
Description: 
"""

class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] == i:
                return i
        return -1