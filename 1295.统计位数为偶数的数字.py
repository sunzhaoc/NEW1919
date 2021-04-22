'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 12:08:28
LastEditTime: 2021-04-22 12:12:34
FilePath: \Leetcode\1295.统计位数为偶数的数字.py
'''
#
# @lc app=leetcode.cn id=1295 lang=python3
#
# [1295] 统计位数为偶数的数字
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 88.43%    O(n) = 
MEMORY: 15.1MB    BEAT:  5.15%    O(n) = 
USED TIME: 03:21
LAST EDIT TIME: 2021年4月22日12:12:20
Description: 
"""

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for x in nums:
            if (x >= 10 and x <= 99) or (x >= 1000 and x <= 9999) or (x >= 100000 and x <= 999999): cnt += 1
        return cnt
# @lc code=end

