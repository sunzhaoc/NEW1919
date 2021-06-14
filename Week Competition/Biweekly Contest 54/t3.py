'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2021-06-12 21:44:27
LastEditTime: 2021-06-12 23:00:40
FilePath: \Leetcode\Week Competition\Biweekly Contest 54\t3.py
'''
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        Row,  Col = len(grid), len(grid[0])
        
        #每行的前缀和
        row_pre = [[0 for _ in range(Col + 1)] for _ in range(Row)]
        for r in range(Row):
            for c in range(0, Col):
                row_pre[r][c+1] = row_pre[r][c] + grid[r][c]
    
        #每列的前缀和
        col_pre = [[0 for _ in range(Row + 1)] for _ in range(Col)]
        for c in range(Col):
            for r in range(Row):
                col_pre[c][r+1] = col_pre[c][r] + grid[r][c]
    
        res = 1
        for r in range(Row):
            for c in range(Col):
                for k in range(res + 1, 50 + 1):
                    nr = r + k - 1          #右下角的位置！！！！
                    nc = c + k - 1
                    if nr >= Row or nc >= Col:  #边长太长了，超界了。
                        break
                        
                    ok = True
                    ###取一行的和，作为目标和
                    cur_sum = row_pre[r][nc+1] - row_pre[r][c]

                    #---- 先检查行
                    for rr in range(r + 1, nr + 1):
                        if row_pre[rr][nc+1] - row_pre[rr][c] != cur_sum:
                            ok = False
                            break
                        
                    if ok == True:
                        #----再检查列
                        for cc in range(c, nc + 1):
                            if col_pre[cc][nr+1] - col_pre[cc][r] != cur_sum:
                                ok = False
                                break



                    if ok == True:
                        #---- 再检查斜线
                        pos_sum = grid[r][c]
                        pr = r
                        pc = c
                        for _ in range(k - 1):
                            pr += 1
                            pc += 1
                            pos_sum += grid[pr][pc]
                        if pos_sum != cur_sum :
                            ok = False
                    if ok == True:
                        #---- 再检查副对角线
                        neg_sum = grid[r][nc]
                        ner = r
                        nec = nc
                        for _ in range(k - 1):
                            ner += 1
                            nec -= 1
                            neg_sum += grid[ner][nec]
                        if neg_sum != cur_sum:
                            ok = False
                    if ok == True:
                        res = max(res, k)
        return res