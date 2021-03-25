'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-01-19 10:13:27
LastEditTime: 2021-03-16 16:00:53
FilePath: \Leetcode\Python3\change.py
'''

class Solution:
    def changeKuohao(self, A):
        B = ""

        for i in A:
            if i == "[":
                B += "{"
            elif i == "]":
                B += "}"
            else:
                B += i
        return B


sol = Solution()
x = sol.changeKuohao("[[0, 1], [1, 2], [1, 3], [1, 10], [1, 11], [1, 4], [2, 4], [2, 6], [2, 9], [2, 10], [2, 4], [2, 5], [2, 10], [3, 7], [3, 7], [4, 5], [4, 11], [4, 11], [4, 10], [5, 7], [5, 10], [6, 8], [7, 11], [8, 10]]")
print(x)