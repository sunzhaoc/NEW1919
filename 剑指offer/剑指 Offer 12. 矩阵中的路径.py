'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-15 20:45:42
LastEditTime: 2020-12-15 22:03:06
FilePath: \Leetcode\剑指 Offer 12. 矩阵中的路径.py
'''


"""
RESULT: Accept
TIME:    268ms    BEAT: 27.81%    O(n) = 
MEMORY: 18.4MB    BEAT:  5.00%    O(n) = 
Description: 回溯 + 剪枝
"""

class Solution:
    def exist(self, board, word):
        row, col = len(board), len(board[0])

        def backTrack(row, col, length):
            if not 0 <= row < len(board) or not 0 <= col < len(board[0]) or board[row][col] != word[length]:   return False
            if length == len(word) - 1: return True
            board[row][col] = ''
            res = backTrack(row + 1, col, length + 1) or backTrack(row - 1, col, length + 1) or backTrack(row, col + 1, length + 1) or backTrack(row, col - 1, length + 1)
            board[row][col] = word[length]
            return res


        for row in range(len(board)):
            for col in range(len(board[0])):
                if backTrack(row, col, 0): return True
        return False


sol = Solution()
A = sol.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")
print(A)
        