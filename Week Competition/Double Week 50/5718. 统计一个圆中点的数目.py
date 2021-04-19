'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-17 22:14:25
LastEditTime: 2021-04-17 23:17:00
FilePath: \Leetcode\weekcom\Double Week 50\T2.py
'''

class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res = []
        for i in range(len(queries)):
            cnt = 0
            for j in range(len(points)):
                x = points[j][0]
                y = points[j][1]
                if (x - queries[i][0]) * (x - queries[i][0]) + (y - queries[i][1]) * (y - queries[i][1]) <= queries[i][2] * queries[i][2]: c += 1
            res.append(cnt)
        return cnt