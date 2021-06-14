'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2021-06-13 13:27:31
LastEditTime: 2021-06-13 14:45:45
FilePath: \Leetcode\Week Competition\Weekly Contest 245\5786. 可移除字符的最大数目.py
'''

class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        def checksubSeq(s, p, mid):
            se = set(removable[: mid + 1])
            i = j = 0
            while i < len(s) and j < len(p):
                if j in se: 
                    j += 1
                    continue
                if s[i] == p[j]: j += 1
                i += 1
            return j == len(p)
            
        l, r = 0, len(removable) - 1
        while l <= r:
            mid = (l + r) // 2
            if checksubSeq(s, p, mid): l = mid + 1
            else: r = mid - 1
        return l
