'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-02 20:44:20
LastEditTime: 2021-03-02 20:47:35
FilePath: \Leetcode\766.托普利茨矩阵.py
'''
#
# @lc app=leetcode.cn id=766 lang=python3
#
# [766] 托普利茨矩阵
#

# @lc code=start

"""
RESULT: Accept
TIME:     44ms    BEAT: 64.48%    O(n) = mn
MEMORY: 14.7MB    BEAT: 87.39%    O(n) = 1
USED TIME: 02:00
LAST EDIT TIME: 2021年3月2日20:47:5
Description: 
"""

class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        row, col = len(matrix), len(matrix[0])
        
        for i in range(1, row):
            for j in range(1, col):
                if matrix[i][j] != matrix[i - 1][j - 1]:
                    return False
        return True

# @lc code=end

