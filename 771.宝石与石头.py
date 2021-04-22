'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:08:20
LastEditTime: 2021-04-22 09:10:30
FilePath: \Leetcode\771.宝石与石头.py
'''
#
# @lc app=leetcode.cn id=771 lang=python3
#
# [771] 宝石与石头
#

# @lc code=start
"""
RESULT: Accept
TIME:     36ms    BEAT: 85.73%    O(n) = 
MEMORY: 14.9MB    BEAT: 58.86%    O(n) = 
USED TIME: 01:25
LAST EDIT TIME: 2021年4月22日9:10:9
Description: 
"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewelsSet = set(jewels)
        return sum(s in jewelsSet for s in stones)
# @lc code=end

