'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-22 09:10:48
LastEditTime: 2021-04-22 09:12:51
FilePath: \Leetcode\1672.最富有客户的资产总量.py
'''
#
# @lc app=leetcode.cn id=1672 lang=python3
#
# [1672] 最富有客户的资产总量
#

# @lc code=start
"""
RESULT: Accept
TIME:   40ms    BEAT: 65.19%    O(n) = 
MEMORY: 15MB    BEAT:  8.21%    O(n) = 
USED TIME: 01:33
LAST EDIT TIME: 2021年4月22日9:12:46
Description: 
"""

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        res = 0
        for i in range(len(accounts)):
            sum = 0
            for x in accounts[i]:
                sum += x
            res = max(res, sum)
        return res
# @lc code=end

