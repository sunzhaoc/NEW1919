'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 16:39:35
LastEditTime: 2020-11-30 16:59:47
FilePath: \Leetcode\46.全排列.py
'''
#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start
class Solution:
    def permute(self, nums):
        res = []
        n = len(nums)

        def backTrack(level, choose_list, tochoose_list):
            if level == n:
                res.append(choose_list)
            for i in range(len(tochoose_list)):
                backTrack(level + 1, choose_list + [tochoose_list[i]], tochoose_list[:i] + tochoose_list[i + 1:])
                
        backTrack(0, [], nums)

        return res


sol = Solution()
A = sol.permute([1, 2, 3])
print(A)
# @lc code=end

