'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-09 09:26:43
LastEditTime: 2020-12-09 10:28:32
FilePath: \Leetcode\62.不同路径.py
'''
#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start

"""
RESULT: Accept
TIME:     40ms    BEAT: 67.30%    O(n) = m
MEMORY: 13.5MB    BEAT: 44.86%    O(n) = 1
Description: 利用数学组合数知识解决。因为m，n可互换，利用这点可以降低运算时间。
"""

class Solution:
    def uniquePaths(self, m, n):
        sum = 1
        for i in range(max(m, n), min(m, n) + max(m, n) - 2 + 1):
            sum *= i
        for i in range(1, min(m, n) - 1 + 1):
            sum /= i
        return int(sum)
        

"""
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) =  
Description: 回溯法，此方法会超时。
"""

# class Solution:
#     def uniquePaths(self, row, col):
#         right = col - 1
#         down = row - 1

#         def backTrack(right, down, ans):
#             if right == 0 and down == 0: 
#                 ans += 1
#                 return ans
#             if right == 0:
#                 ans = backTrack(right, down - 1, ans)
#             if down == 0:
#                 ans = backTrack(right - 1, down, ans)
#             if down != 0 and right != 0:
#                 ans = backTrack(right - 1, down, ans)
#                 ans = backTrack(right, down - 1, ans)
#             return ans
            
#         return backTrack(right, down, 0)


sol = Solution()
# A = sol.uniquePaths(3, 2)
A = sol.uniquePaths(7, 3)
print(A)
# @lc code=end

