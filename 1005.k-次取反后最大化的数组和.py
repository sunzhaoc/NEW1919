'''
Description: 
Version: 1.0
Autuor: 冰凝水
Date: 2020-11-13 14:47:12
LastEditTime: 2020-11-13 16:22:27
FilePath: \Leetcode\Chinese\1005.k-次取反后最大化的数组和.py
'''
#
# @lc app=leetcode.cn id=1005 lang=python3
#
# [1005] K 次取反后最大化的数组和
#

# @lc code=start
class Solution:
    def largestSumAfterKNegations(self, A, K):
        for i in range(K):
            A.sort()
            A[0] = -A[0]
        
        return sum(A)


sol = Solution()
A = sol.largestSumAfterKNegations([3,-1,0,2], 3)
print(A)
# @lc code=end

