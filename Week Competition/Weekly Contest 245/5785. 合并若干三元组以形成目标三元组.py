'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2021-06-13 12:34:05
LastEditTime: 2021-06-13 12:37:06
FilePath: \Leetcode\Week Competition\Weekly Contest 245\5785. 合并若干三元组以形成目标三元组.py
'''

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        res = [0] * 3
        for i in range(len(triplets)):
            a, b, c = triplets[i][0], triplets[i][1], triplets[i][2]
            if a <= target[0] and b <= target[1] and c <= target[2]:
                res[0], res[1], res[2] = max(res[0], a), max(res[1], b), max(res[2], c)
        for i in range(len(target)):
            if res[i] != target[i]: return False
        return True