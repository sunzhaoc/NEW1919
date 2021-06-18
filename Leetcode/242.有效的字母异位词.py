'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-03-03 15:59:43
LastEditTime: 2021-03-03 16:07:26
FilePath: \Leetcode\242.有效的字母异位词.py
'''
#
# @lc app=leetcode.cn id=242 lang=python3
#
# [242] 有效的字母异位词
#

# @lc code=start


"""
RESULT: Accept
TIME:     64ms    BEAT: 37.94%    O(n) = nlogn
MEMORY: 15.6MB    BEAT:  9.12%    O(n) = logn
USED TIME: 06:43
LAST EDIT TIME: 2021年3月3日16:6:50
Description: 
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        tmpS = list(s)
        tmpT = list(t)
        tmpS.sort()
        tmpT.sort()
        s = "".join(tmpS)
        t = "".join(tmpT)
        return s == t


sol = Solution()
ans = sol.isAnagram("a", "b")
# @lc code=end

