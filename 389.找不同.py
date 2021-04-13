'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-18 12:08:52
LastEditTime: 2020-12-18 12:44:48
FilePath: \Leetcode\389.找不同.py
'''
#
# @lc app=leetcode.cn id=389 lang=python3
#
# [389] 找不同
#

# @lc code=start


"""
RESULT: Accept
TIME:     44ms    BEAT: 60.53%    O(n) = n
MEMORY: 14.8MB    BEAT:  5.13%    O(n) = 26
Description: 用哈希表计数。
"""

class Solution:
    def findTheDifference(self, s, t):
        dic = collections.Counter(s)
        for i in t:
            if i not in dic or dic[i] == 0:    return i
            else: dic[i] -= 1


sol = Solution()
ans = sol.findTheDifference("abcd", "abcde")
print(ans)
        
# @lc code=end

