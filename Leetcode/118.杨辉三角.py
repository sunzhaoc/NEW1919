#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#

# @lc code=start
"""
RESULT: Accept
TIME:     32ms    BEAT: 93.78%    O(n) = n^2
MEMORY: 13.6MB    BEAT: 15.89%    O(n) = 1
Description: 
"""
class Solution:
    def generate(self, numRows):
        if numRows == 0:    return []
        if numRows == 1:    return [[1]]
        if numRows == 2:    return [[1], [1, 1]]

        ans = [[1], [1, 1]]
        for row in range(3, numRows + 1):
            ans.append([1] * row)
            for i in range(row - 2):
                ans[row - 1][1 + i] = ans[row - 2][i] + ans[row - 2][i + 1]
        
        return ans


sol = Solution()
A = sol.generate(5)
print(A)
# @lc code=end

