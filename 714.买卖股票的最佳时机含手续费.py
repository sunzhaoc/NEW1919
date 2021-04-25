'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-17 20:23:38
LastEditTime: 2020-12-17 20:32:35
FilePath: \Leetcode\714.买卖股票的最佳时机含手续费.py
'''
#
# @lc app=leetcode.cn id=714 lang=python3
#
# [714] 买卖股票的最佳时机含手续费
#

# @lc code=start


"""
RESULT: Accept
TIME:    904ms    BEAT: 68.62%    O(n) = n
MEMORY: 21.4MB    BEAT: 38.40%    O(n) = 1
Description: 贪心
"""

class Solution:
    def maxProfit(self, prices, fee):
        buy = prices[0] + fee
        profit = 0
        
        for i in range(1, len(prices)):
            if prices[i] + fee < buy:   buy = prices[i] + fee
            elif prices[i] > buy:
                profit += prices[i] - buy
                buy = prices[i]
        
        return profit


sol = Solution()
ans = sol.maxProfit([1, 3, 2, 8, 4, 9], 2)
print(ans)

# @lc code=end

