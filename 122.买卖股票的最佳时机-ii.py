'''
Description: 
Version: 1.0
Autuor: 冰凝水
Date: 2020-11-12 21:10:23
LastEditTime: 2020-11-12 21:26:50
FilePath: \Leetcode\Chinese\122.买卖股票的最佳时机-ii.py
'''
#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices):
        num = len(prices)
        ans = 0
        for i in range(num-1):
            ans += max(0, prices[i + 1] - prices[i])

        return ans


sol = Solution()
A = sol.maxProfit([7,1,5,3,6,4])
print(A)
# @lc code=end

