'''
Description: 
Version: 1.0
Autor: Vicro
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 21:38:25
FilePath: /Leetcode/Chinese/1337.方阵中战斗力最弱的-k-行.py
'''
#
# @lc app=leetcode.cn id=1337 lang=python3
#
# [1337] 方阵中战斗力最弱的 K 行
#

# @lc code=start
class Solution:
    def kWeakestRows(self, mat, k):
        result = [(sum(mat[i]), i) for i in range(len(mat))]
        result.sort()
        print(result[:k])
        return [i[1] for i in result[:k]]


sol = Solution()
sol.kWeakestRows([[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]], 3)
# @lc code=end

