'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 21:01:59
LastEditTime: 2020-11-30 21:30:19
FilePath: \Leetcode\40.组合总和-ii.py
'''
#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#

# @lc code=start
class Solution:
    def combinationSum2(self, candidates, target):
        res = []
        n = len(candidates)
        candidates.sort()
        def backTrack(cha, list, use_list):
            if cha == 0:
                res.append(list)
                return
            # if cha < 0:
            #     return
            for i in range(len(use_list)):
                if cha - use_list[i] < 0:
                    break
                if use_list[i] == use_list[i - 1] and i > 0:
                    continue
                backTrack(cha - use_list[i], list + [use_list[i]], use_list[i+1:])

        backTrack(target, [], candidates)
        return res

sol = Solution()
A = sol.combinationSum2([1], 1)
print(A)

# @lc code=end

