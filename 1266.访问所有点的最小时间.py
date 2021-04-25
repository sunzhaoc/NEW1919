'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 10:55:34
LastEditTime: 2021-04-22 11:11:29
FilePath: \Leetcode\1266.访问所有点的最小时间.py
'''
#
# @lc app=leetcode.cn id=1266 lang=python3
#
# [1266] 访问所有点的最小时间
#

# @lc code=start
"""
RESULT: Accept
TIME:   48ms    BEAT: 34.76%    O(n) = 
MEMORY: 15MB    BEAT: 10.11%    O(n) = 
USED TIME: 15:11
LAST EDIT TIME: 2021年4月22日11:11:1
Description: 切比雪夫距离。
"""

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        cnt = 0
        x0, x1 = points[0][0], points[0][1]
        for i in range(1, len(points)):
            y0, y1 = points[i]
            cnt += max(abs(x0 - y0), abs(x1 - y1))
            x0, x1 = points[i]

        return cnt
            
# @lc code=end
