'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-21 15:24:03
LastEditTime: 2020-11-23 14:32:32
FilePath: \Leetcode\Chinese\435.无重叠区间.py
'''
#
# @lc app=leetcode.cn id=435 lang=python3
#
# [435] 无重叠区间
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals):
        if not intervals: return 0
        intervals.sort(key = lambda x: x[1])
        end = intervals[0][1]
        ans = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < end:
                ans += 1
            else:
                end = intervals[i][1]
        return ans

sol = Solution()
A = sol.eraseOverlapIntervals([[0,2],[1,3],[2,4],[3,5],[4,6]])
print(A)
# @lc code=end

