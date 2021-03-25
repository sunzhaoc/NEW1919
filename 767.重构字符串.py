'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-30 13:20:22
LastEditTime: 2020-12-02 15:38:20
FilePath: \Leetcode\767.重构字符串.py
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
        
        # a, b = S[:n], S[n:]
        # for i in range(len(a)):
        #     S[i * 2] = a[i]
        # for i in range(len(b)):
        #     S[i * 2 + 1] = b[i]   
            
        # return ''.join(S)

        return ''.join(j for i in zip(S, S[n:]) for j in i) + ''.join(S[n - 1]) * len(S) % 2

sol = Solution()
A = sol.reorganizeString("abcdeeffgg")
print(A)
# @lc code=end
