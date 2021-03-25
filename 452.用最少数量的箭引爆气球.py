'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-23 14:35:55
LastEditTime: 2020-11-23 15:09:59
FilePath: \Leetcode\Chinese\452.用最少数量的箭引爆气球.py
'''
#
# @lc app=leetcode.cn id=452 lang=python3
#
# [452] 用最少数量的箭引爆气球
#

# @lc code=start
class Solution:
    def findMinArrowShots(self, points):
        if not points: return 0
        points.sort(key=lambda x: x[1])
        ans = 1
        end = points[0][1]
        for i in range(1, len(points)):
            if points[i][0] <= end:
                continue
            end = points[i][1]
            ans += 1
        return ans
        

sol = Solution()
# A = sol.findMinArrowShots([[10,16],[2,8],[1,6],[7,12]])
A = sol.findMinArrowShots([])
print(A)
# @lc code=end

