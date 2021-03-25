'''
Description: 
Version: 1.0
Autor: Vicro
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-06 22:19:22
FilePath: /Leetcode/Chinese/744.寻找比目标字母大的最小字母.py
'''
#
# @lc app=leetcode.cn id=744 lang=python3
#
# [744] 寻找比目标字母大的最小字母
#

# @lc code=start
class Solution:
    def nextGreatestLetter(self, letters, target):
        l, r = 0, len(letters) - 1
        while l < r:
            mid = (r - l + 1) // 2 + l
            if letters[mid] > target:
                r = mid - 1
            else:
                l = mid
        
        if letters[l] > target:
            return letters[l]
        elif (l + 1) <= (len(letters) - 1):
            return letters[l + 1]
        else:
            return letters[0]
sol = Solution()
print(sol.nextGreatestLetter(["e","e","e","e","e","e","n","n","n","n"], "e"))
# @lc code=end

