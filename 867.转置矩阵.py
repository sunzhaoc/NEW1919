'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-29 21:43:24
LastEditTime: 2020-11-29 21:52:34
FilePath: \Leetcode\867.转置矩阵.py
'''
#
# @lc app=leetcode.cn id=867 lang=python3
#
# [867] 转置矩阵
#

# @lc code=start
class Solution:
    def transpose(self, A):
        if not A: return None
        ans = []
        for i in range(len(A[0])):
            ans.append([])
            for j in range(len(A)):
                ans[i].append(A[j][i])
        
        return ans
                
            


sol = Solution()
A = sol.transpose([[1,2,3],[4,5,6],[7,8,9]])
print(A)
        
# @lc code=end

