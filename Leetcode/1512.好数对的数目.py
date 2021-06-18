'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 09:13:14
LastEditTime: 2021-04-22 09:15:07
FilePath: \Leetcode\1512.好数对的数目.py
'''
#
# @lc app=leetcode.cn id=1512 lang=python3
#
# [1512] 好数对的数目
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 68.92%    O(n) = 
MEMORY: 14.8MB    BEAT: 76.44%    O(n) = 
USED TIME: 01:13
LAST EDIT TIME: 2021年4月22日9:15:12
Description: 
"""

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]: cnt += 1
        return cnt
# @lc code=end

