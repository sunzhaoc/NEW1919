'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-20 19:40:51
LastEditTime: 2020-12-20 19:41:42
FilePath: \Leetcode\316.去除重复字母.py
'''
#
# @lc app=leetcode.cn id=316 lang=python3
#
# [316] 去除重复字母
#

# @lc code=start
import collections

class Solution:
    def removeDuplicateLetters(self, s):
        stack = []
        remain_counter = collections.Counter(s)

        for c in s:
            if c not in stack:
                while stack and c < stack[-1] and  remain_counter[stack[-1]] > 0:
                    stack.pop()
                stack.append(c)
            remain_counter[c] -= 1
        return ''.join(stack)


sol = Solution()
ans = sol.removeDuplicateLetters("cbacdcbc")
# @lc code=end

