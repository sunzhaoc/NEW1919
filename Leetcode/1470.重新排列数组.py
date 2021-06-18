'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 09:18:59
LastEditTime: 2021-04-22 09:22:10
FilePath: \Leetcode\1470.重新排列数组.py
'''
#
# @lc app=leetcode.cn id=1470 lang=python3
#
# [1470] 重新排列数组
#

# @lc code=start
"""
RESULT: Accept
TIME:   40ms    BEAT: 75.71%    O(n) = 
MEMORY: 15MB    BEAT: 54.80%    O(n) = 
USED TIME: 02:41
LAST EDIT TIME: 2021年4月22日9:21:59
Description: 
"""

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        mid = len(nums) // 2
        res = []
        for i in range(mid, len(nums)):
            res.append(nums[i - mid])
            res.append(nums[i])
        return res
# @lc code=end

