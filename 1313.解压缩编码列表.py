'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 10:16:52
LastEditTime: 2021-04-22 10:19:47
FilePath: \Leetcode\1313.解压缩编码列表.py
'''
#
# @lc app=leetcode.cn id=1313 lang=python3
#
# [1313] 解压缩编码列表
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 80.87%    O(n) = 
MEMORY: 15.1MB    BEAT: 17.81%    O(n) = 
USED TIME: 02:19
LAST EDIT TIME: 2021年4月22日10:19:30
Description: 
"""

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums) // 2):
            frep = nums[2 * i]
            val = nums[2 * i + 1]
            res += [val] * frep
        return res
# @lc code=end

