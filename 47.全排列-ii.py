'''
Description: ()
Version: 1.0
Author: Vicro
Date: 2020-11-30 17:01:12
LastEditTime: 2020-11-30 17:05:10
FilePath: \Leetcode\47.全排列-ii.py
'''
#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#

# @lc code=start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        nums.sort()

        def backTrack(level, choose_list, tochoose_list):
            if level == n and choose_list not in res:
                res.append(choose_list)
            for i in range(len(tochoose_list)):
                backTrack(level + 1, choose_list + [tochoose_list[i]], tochoose_list[:i] + tochoose_list[i + 1:])
                
        backTrack(0, [], nums)

        return res
# @lc code=end

