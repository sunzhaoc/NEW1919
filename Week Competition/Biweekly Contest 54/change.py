'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-01-19 10:13:27
LastEditTime: 2021-06-12 22:56:05
FilePath: \Leetcode\Week Competition\Biweekly Contest 54\change.py
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
x = sol.changeKuohao("[[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]")
print(x)