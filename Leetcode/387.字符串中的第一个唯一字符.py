'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-23 19:36:00
LastEditTime: 2020-12-23 19:45:41
FilePath: \Leetcode\387.字符串中的第一个唯一字符.py
'''
#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#

# @lc code=start

"""
RESULT: Accept
TIME:    104ms    BEAT: 77.33%    O(n) = n
MEMORY: 14.7MB    BEAT: 10.40%    O(n) = <=26
Description: 哈希表。使用哈希表存储频数。
"""

import collections

class Solution:
    def firstUniqChar(self, s):
        dict = collections.Counter(s)

        for i, ch in enumerate(s):
            if dict[ch] == 1:
                return i
        
        return -1


sol = Solution()
ans = sol.firstUniqChar("leetcode")
print(ans)

# @lc code=end

