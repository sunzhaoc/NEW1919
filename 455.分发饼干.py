'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-12 21:34:22
LastEditTime: 2020-11-25 19:26:37
FilePath: \Leetcode\455.分发饼干.py
'''
#
# @lc app=leetcode.cn id=455 lang=python3
#
# [455] 分发饼干
#

# @lc code=start
class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        kid = 0

        for i in s:
            if kid == len(g):
                break
            if g[kid] <= i:
                kid += 1

        return kid    


sol = Solution()
A = sol.findContentChildren([1,2], [1,2,3])
print(A)
# @lc code=end

