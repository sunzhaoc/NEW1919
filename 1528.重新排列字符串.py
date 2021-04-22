'''
Description:
Version: 1.0
Autor: Vicro
Date: 2021-04-22 15:42:44
LastEditTime: 2021-04-22 15:47:32
FilePath: \Leetcode\1528.重新排列字符串.py
'''
#
# @lc app=leetcode.cn id=1528 lang=python3
#
# [1528] 重新排列字符串
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 84.36%    O(n) = n
MEMORY: 15.1MB    BEAT:  5.40%    O(n) = n
USED TIME: 04:17
LAST EDIT TIME: 2021年4月22日15:47:20
Description: 
"""

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        length = len(s)
        res = [""] * length
        for i, ch in enumerate(s):
            res[indices[i]] = ch
        return "".join(res)
# @lc code=end

