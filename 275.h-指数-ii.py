'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-10-07 20:38:29
LastEditTime: 2020-10-07 21:17:44
FilePath: \Leetcode\Chinese\275.h-指数-ii.py
'''
#
# @lc app=leetcode.cn id=275 lang=python3
#
# [275] H 指数 II
#

# @lc code=start
class Solution:
    def hIndex(self, citations):
        l, r = 0, len(citations) - 1
        if citations == []:
            return 0
        if citations[len(citations) - 1] == 0:
            return 0
        while l < r:
            mid = (r - l) // 2 + l
            
            if len(citations) - mid == citations[mid]:
                return len(citations) - mid
            if len(citations) - mid > citations[mid]:
                l = mid + 1
            else:
                r = mid
        return len(citations) - l


sol = Solution()
print(sol.hIndex([]))
sol.hIndex([])
# @lc code=end

