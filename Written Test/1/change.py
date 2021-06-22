'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-01-19 10:13:27
LastEditTime: 2021-04-25 10:15:30
FilePath: \Leetcode\change.py
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
x = sol.changeKuohao("")
print(x)