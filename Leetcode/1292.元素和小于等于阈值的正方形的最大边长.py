'''
Description: 
Version: 1.0
Autuor: 冰凝水
Date: 2020-10-08 21:18:56
LastEditTime: 2020-10-13 21:55:31
FilePath: /Leetcode/Chinese/1292.元素和小于等于阈值的正方形的最大边长.py
'''
#
# @lc app=leetcode.cn id=1292 lang=python3
#
# [1292] 元素和小于等于阈值的正方形的最大边长
#

# @lc code=start
class Solution:
    def maxSideLength(self, mat, threshold):
        m, n = len(mat), len(mat[0])
        P = [[0] * (n + 1) for _ in range (m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1]
        
        def getRect(x1, y1, x2, y2):
            return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1]

        l, r = 1, min(m, n)
        ans = 0
        find = False
        while l <= r:
            mid = (r - l) // 2 + l

            # for i in range(0, m - mid + 1):
            #     for j in range(0, n - mid + 1):
            #         A = getRect(i + 1, j + 1, i + mid, j + mid)
            #         if A <= threshold:
            #             find = True
            #             break
            #     if A <= threshold:
            #         break

            # find = any(getRect(i + 1, j + 1, i + mid, j + mid) <= threshold for i in range(0, m - mid + 1) for j in range(0, m - mid + 1))
            find = any(getRect(i, j, i + mid - 1, j + mid - 1) <= threshold for i in range(1, m - mid + 2) for j in range(1, n - mid + 2))
            if find:
                ans = mid
                l = mid + 1
                # find = False
            else:
                r = mid - 1
        return ans
            


sol = Solution()
A = sol.maxSideLength([[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], 4)
print(A)
# @lc code=end

