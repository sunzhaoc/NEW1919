'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:15:27
LastEditTime: 2021-04-22 09:18:25
FilePath: \Leetcode\1431.拥有最多糖果的孩子.py
'''
#
# @lc app=leetcode.cn id=1431 lang=python3
#
# [1431] 拥有最多糖果的孩子
#

# @lc code=start
"""
RESULT: Accept
TIME:     36ms    BEAT: 87.13%    O(n) = 
MEMORY: 15.1MB    BEAT:  5.30%    O(n) = 
USED TIME: 02:20
LAST EDIT TIME: 2021年4月22日9:18:10
Description: 
"""

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxNum = -1
        res = []
        for x in candies:
            maxNum = max(maxNum, x)
        for x in candies:
            if x + extraCandies >= maxNum:
                res.append(True)
            else:
                res.append(False)
        return res
        
# @lc code=end

