'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-10-07 21:20:12
LastEditTime: 2020-10-07 21:43:29
FilePath: \Leetcode\Chinese\74.搜索二维矩阵.py
'''
#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0:
            return False
        if len(matrix[0]) == 0:
            return False
        l, r = 0, (len(matrix) * len(matrix[0]) - 1)
        while l < r:
            mid = (r - l) // 2 + l
            if matrix[mid // (len(matrix[0]))][mid % (len(matrix[0]))] == target:
                return True
            if matrix[mid // (len(matrix[0]))][mid % (len(matrix[0]))] < target:
                l = mid + 1
            else:
                r = mid
        
        if matrix[l // (len(matrix[0]))][l % (len(matrix[0]))] == target:
            return True
        else:
            return False


sol = Solution()
print(sol.searchMatrix([[1], [3]], 0))

sol.searchMatrix([[1], [3]], 0)

# @lc code=end

