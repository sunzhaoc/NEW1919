'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 21:37:48
LastEditTime: 2021-04-22 21:41:59
FilePath: \Leetcode\311. 稀疏矩阵的乘法.py
'''

"""
RESULT: Accept
TIME:    160ms    BEAT: %    O(n) = 
MEMORY: 15.2MB    BEAT: %    O(n) = 
USED TIME: 03:46
LAST EDIT TIME: 2021年4月22日21:41:53
Description: 
"""

class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        r1, r2 = len(mat1), len(mat2)
        c1, c2 = len(mat1[0]), len(mat2[0])

        res = [[0 for _ in range(c2)] for _ in range(r1)]

        for r in range(r1):
            for c in range(c2):
                for i in range(c1):
                    res[r][c] += mat1[r][i] * mat2[i][c]
        
        return res