'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 13:15:08
LastEditTime: 2021-04-22 13:19:29
FilePath: \Leetcode\1572.矩阵对角线元素的和.py
'''
#
# @lc app=leetcode.cn id=1572 lang=python3
#
# [1572] 矩阵对角线元素的和
#

# @lc code=start
"""
RESULT: Accept
TIME:     36ms    BEAT: 92.22%    O(n) = 
MEMORY: 15.1MB    BEAT: 15.68%    O(n) = 
USED TIME: 03:30
LAST EDIT TIME: 2021年4月22日13:19:14
Description: 
"""

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sum = 0
        n = len(mat)
        for i in range(n):
            sum += mat[i][i] + mat[i][n - i]
        if n % 2 == 1:
            sum -= mat[n / 2][n / 2]
        return sum
# @lc code=end

