'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 15:56:54
LastEditTime: 2020-11-30 16:37:12
FilePath: \Leetcode\90.子集-ii.py
'''
#
# @lc app=leetcode.cn id=90 lang=python3
#
# [90] 子集 II
#

# @lc code=start
class Solution:
    def subsetsWithDup(self, nums):
        res = []
        n = len(nums)

        nums.sort()

        def backTrack(level, list):
            if list not in res:
                res.append(list)

            for i in range(level, n):
                backTrack(i + 1, list + [nums[i]])

        backTrack(0, [])
        return res

sol = Solution()
A = sol.subsetsWithDup([1,2,2])
print(A)

# @lc code=end

