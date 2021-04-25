'''
@Description: 
@Version: 1.0
@Autor: 冰凝水
@Date: 2020-07-27 16:41:58
@LastEditors: 冰凝水
@LastEditTime: 2020-07-27 22:15:09
'''
#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def lcp(start, end):
            if start == end:
                return strs[start]
            
            mid = (start + end) // 2
            
            Left, Right = lcp(start, mid), lcp(mid + 1, end)
            minLength = min(len(Left), len(Right))
            for i in range(minLength):
                if Left[i] != Right[i]:
                    return Left[:i]
            return Left[:minLength]
            
        return "" if not strs else lcp(0, len(strs)-1)

# @lc code=end

