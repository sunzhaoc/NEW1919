'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 21:13:13
FilePath: /Leetcode/Chinese/441.排列硬币.py
'''
#
# @lc app=leetcode.cn id=441 lang=python3
#
# [441] 排列硬币
#

# @lc code=start
class Solution:
    def arrangeCoins(self, n):
        if n == 0:
            return 0
        l, r = 1, n
        while l < r:
            mid = (r - l + 1) // 2 + l
            
            num = (1 + mid) * mid / 2
            if num == n:
                return mid
            elif num <= n:
                l = mid
            else:
                r = mid - 1
        return l


sol = Solution()
print(sol.arrangeCoins(3))
# @lc code=end

