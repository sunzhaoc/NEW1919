'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-10-08 19:45:37
LastEditTime: 2020-10-08 20:39:34
FilePath: \Leetcode\Chinese\378.有序矩阵中第k小的元素.py
'''
#
# @lc app=leetcode.cn id=378 lang=python3
#
# [378] 有序矩阵中第K小的元素
#

# @lc code=start
class Solution:
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[len(matrix) - 1][len(matrix) - 1]
        while l < r:
            mid = (r - l) // 2 + l
            num = self.num_Caculate(matrix, mid)
            if num == k and mid in matrix:
                return mid
            if num < k:
                l = mid + 1
            else:
                r = mid
        return l

    def num_Caculate(self, matrix, mid):
        i = len(matrix) - 1 #　Row
        j = 0   # Column
        num = 0
        while i >= 0 and j < len(matrix):
            if matrix[i][j] <= mid:
                num += i + 1
                j += 1
            else:
                i -= 1
        return num

sol = Solution()
A = sol.kthSmallest([[1,5,9],[10,11,13],[12,13,15]], 8)
print(A)
# @lc code=end

