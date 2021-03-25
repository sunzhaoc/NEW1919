'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-10-08 21:00:02
LastEditTime: 2020-10-08 21:17:11
FilePath: \Leetcode\Chinese\1011.在-d-天内送达包裹的能力.py
'''
#
# @lc app=leetcode.cn id=1011 lang=python3
#
# [1011] 在 D 天内送达包裹的能力
#

# @lc code=start
class Solution:
    def shipWithinDays(self, weights, D):
        l, r = max(weights), sum(weights)

        while l < r:
            mid = (r - l) // 2 + l
            day = self.weightWhetherWork(weights, mid)
            if day > D:
                l = mid + 1
            else:
                r = mid
        return l

    def weightWhetherWork(self, weights, mid):
        temp = mid
        day = 1
        for i in weights:
            if temp >= i:
                temp -= i
            else: 
                temp = mid
                temp -= i
                day += 1
        return day


sol = Solution()
A = sol.shipWithinDays([3,2,2,4,1,4],3)
print(A)
# @lc code=end

