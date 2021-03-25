'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-02 19:32:51
LastEditTime: 2020-12-02 19:46:58
FilePath: \Leetcode\451.根据字符出现频率排序.py
'''
#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#
import collections
# @lc code=start
class Solution:
    def frequencySort(self, s):
        res = collections.Counter(s)
        res = list(res.items())
        res = sorted(res, key=lambda x: -x[1])
        ans = ""
        for i in res:
            ans += i[0] * i[1]
        return ans


sol = Solution()
A = sol.frequencySort("tree")
print(A)
# @lc code=end

