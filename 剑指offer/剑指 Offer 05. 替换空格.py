'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-03 20:05:44
LastEditTime: 2020-12-03 20:09:09
FilePath: \Leetcode\剑指 Offer 05. 替换空格.py
'''

class Solution:
    def replaceSpace(self, s):
        ans = ""
        for i in s:
            if i == " ":
                ans += "%20"
            else:
                ans += (i)
        return ans


sol = Solution()
A = sol.replaceSpace("We are happy.")
print(A)