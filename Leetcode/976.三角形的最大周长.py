'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-29 22:28:56
LastEditTime: 2020-11-29 22:46:46
FilePath: \Leetcode\976.三角形的最大周长.py
'''
#
# @lc app=leetcode.cn id=976 lang=python3
#
# [976] 三角形的最大周长
#

# @lc code=start
class Solution:
    def largestPerimeter(self, A):
        A.sort(key=lambda x: -x)
        # rac = [A[0], A[1]]
    
        # for i in range(2, len(A)):
        #     rac.append(A[i])
        #     if rac[1] + rac[2] > rac[0]:
        #         return sum(rac)
        #     else:
        #         rac.pop(0)
        # return 0
        
        for i in range(2, len(A)):
            if A[i] + A[i - 1] > A[i - 2]:
                return A[i] + A[i - 1] + A[i - 2]
        return 0


sol = Solution()
A = sol.largestPerimeter([2, 1, 2])
print(A)
        
# @lc code=end

