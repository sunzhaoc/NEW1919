'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 14:53:28
LastEditTime: 2020-11-30 15:46:59
FilePath: \Leetcode\78.子集.py
'''
#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:
    def subsets(self, nums):
        res = []
        n = len(nums)

        def backTrack(level, list):
            res.append(list)

            for i in range(level, n):
                backTrack(i + 1, list + [nums[i]])

        
        backTrack(0, [])
        return res

        
sol = Solution()
A = sol.subsets([1, 2, 3])
print(A)
# @lc code=end