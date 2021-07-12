'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-07-11 10:57:31
FilePath: \Leetcode\Week Competition\Weekly Contest 249\t2.py
'''

"""
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
"""

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        visited = [[[0 for _ in range(26)] for _ in range(26)] for _ in range(26)]
        n = len(s)
        presum = [[0 for _ in range(26)] for _ in range(n + 1)] 
        ch_first_idx = [-1 for _ in range(26)]      
        for r, ch in enumerate(s):
            y = ord(ch) - ord('a')
            if presum[r][y] > 0:       
                l = ch_first_idx[y]    
                for x in range(26):   
                    if presum[r][x] - presum[l+1][x] > 0: visited[y][x][y] = 1
            
            if ch_first_idx[y] == -1: ch_first_idx[y] = r
            presum[r + 1] = presum[r][:]
            presum[r + 1][y] += 1
        
        res = 0
        for y in range(26):
            for x in range(26): res += visited[y][x][y]
        return res
