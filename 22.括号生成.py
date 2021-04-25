'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-07 15:52:38
LastEditTime: 2020-12-07 17:42:14
FilePath: \Leetcode\22.括号生成.py
'''
#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#

# @lc code=start


"""
RESULT: Accept
TIME:     40ms    BEAT: 77.19%    O(n) = n^2
MEMORY: 13.8MB    BEAT: 12.96%    O(n) = n^2
Description: 
"""

class Solution:
    def generateParenthesis(self, n):
        if n == 0:  return []
        ans = [[["(", n - 1, n]]]
        
        for i in range(n * 2 - 1):  
            ans.append([])
            for j in ans[0]:
                if j[1] < j[2]:
                    if j[1] > 0:
                        ans[-1].append([j[0] + "(", j[1] - 1, j[2]])
                    if j[2] > 0:
                        ans[-1].append([j[0] + ")", j[1], j[2] - 1])
                elif j[1] == j[2] and j[1] != 0:
                    ans[-1].append([j[0] + "(", j[1] - 1, j[2]])
            del(ans[0])
        return [i[0] for i in ans[-1]]
            





sol = Solution()
A = sol.generateParenthesis(3)
print(A)
# @lc code=end

