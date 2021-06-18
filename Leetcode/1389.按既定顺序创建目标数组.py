'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 10:13:32
LastEditTime: 2021-04-22 10:16:35
FilePath: \Leetcode\1389.按既定顺序创建目标数组.py
'''
#
# @lc app=leetcode.cn id=1389 lang=python3
#
# [1389] 按既定顺序创建目标数组
#

# @lc code=start
"""
RESULT: Accept
TIME:     32ms    BEAT: 94.71%    O(n) = 
MEMORY: 14.9MB    BEAT: 11.61%    O(n) = 
USED TIME: 01:25
LAST EDIT TIME: 2021年4月22日10:16:40
Description: 
"""

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for i in range(len(nums)):
            target.insert(index[i], nums[i])
        return target
# @lc code=end

