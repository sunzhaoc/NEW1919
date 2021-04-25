'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 13:20:22
LastEditTime: 2021-04-01 16:03:03
FilePath: \Leetcode\Python3\767.重构字符串.py
'''
#
# @lc app=leetcode.cn id=767 lang=python3
#
# [767] 重构字符串
#

# @lc code=start
class Solution:
    def reorganizeString(self, S):
    # def reorganizeString(self, S: str) -> str:
        S = sorted(sorted(S), key=lambda x: S.count(x), reverse=True)
        n = int(len(S) / 2 + 0.5)

        if S[0] == S[n]:
            return ''

        return ''.join(j for i in zip(S, S[n:]) for j in i) + ''.join(S[n - 1]) * len(S) % 2

sol = Solution()
A = sol.reorganizeString("abcdeeffgg")
print(A)
# @lc code=end
