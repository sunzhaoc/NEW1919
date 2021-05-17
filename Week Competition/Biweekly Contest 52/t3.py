'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-05-15 23:55:44
FilePath: \Leetcode\Week Competition\Biweekly Contest 52\t3.py
'''

class Solution:
    def rotateTheBox(self, box):
        m = len(box)
        n = len(box[0])

        res = [[0] * m] * n;
        for i in range(m):
            for j in range(n):
                res[j][m - 1 - i] = box[i][j]
        
        for j in range(m):
            rock, blank = 0, 0;
            for i in range(n):
                if i == n - 1 and res[i][j] != '*':
                    if res[i][j] == '#': rock += 1
                    else: blank += 1
                    k = i
                    while rock:
                        res[k][j] = '#'
                        rock -= 1
                        k -= 1
                    while blank:
                        res[k][j] = '.'
                        blank -= 1
                        k -= 1
                
                elif res[i][j] == '#': rock += 1
                elif res[i][j] == '.': blank += 1
                elif res[i][j] == '*':
                    k = i - 1
                    while rock:
                        res[k][j] = '#'
                        rock -= 1
                        k -= 1
                    while blank:
                        res[k][j] = '.'
                        blank -= 1
                        k -= 1
        return res


sol = Solution()
ans = sol.rotateTheBox([["#",".","*","."],         ["#","#","*","."]])
print(ans)
