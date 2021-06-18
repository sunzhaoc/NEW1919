'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-19 15:11:19
LastEditTime: 2020-11-19 16:02:41
FilePath: \Leetcode\Chinese\861.翻转矩阵后的得分.py
'''
#
# @lc app=leetcode.cn id=861 lang=python3
#
# [861] 翻转矩阵后的得分
#

# @lc code=start
class Solution:
    def matrixScore(self, A):
        # Caculate Row
        for row in range(len(A)):
            if A[row][0] == 0:
                A[row] = [1 - tmp for tmp in A[row]]
        
        # Caculate Col
        for col in range(1, len(A[0])): # you have already make the 1-st element of each row to 1, so you do not need to judge it
            one_num = sum(A[row][col] for row in range(len(A)))
            if one_num < len(A) - one_num: # Zero Num
                for row in range(len(A)):
                    A[row][col] = 1 - A[row][col]

        ans = 0
        # for row in range(len(A)):
        #     for col in range(len(A[0])):
        #         if A[row][col] == 1:
        #             ans += 2**(len(A[0])-1-col)
        for row in range(len(A)):
            tempA = A[i][::-1]
            item = for index, val in range(zip())
        return ans

                
sol = Solution()
B = sol.matrixScore([[0,1],[0,1],[0,1],[0,0]])
print(B)
# @lc code=end

