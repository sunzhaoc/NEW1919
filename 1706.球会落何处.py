'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-28 22:27:04
LastEditTime: 2020-12-28 22:59:27
FilePath: \Leetcode\1706.球会落何处.py
'''

"""
RESULT: Wrong
TIME:   ms    BEAT: %    O(n) = mn
MEMORY: MB    BEAT: %    O(n) = n
Description: DP。 与下面相同，VSCode下正确，相同的用例提交错误。似乎是BUG？
https://leetcode-cn.com/problems/where-will-the-ball-fall/solution/java-shuang-bai-di-gui-by-ethan-jx-yvx6/
"""

class Solution:
    def findBall(self, grid):
        ans = []
        row, col = len(grid), len(grid[0])

        for i in range(len(grid[0])):
            ans.append(i)

        for i in range(row):
            for j in range(col):
                if ans[j] == -1: continue
                elif (grid[i][ans[j]] == 1 and (ans[j] + 1 >= col or grid[i][ans[j] + 1 == -1])) or (grid[i][ans[j]] == -1 and (ans[j] - 1 < 0 or grid[i][ans[j] + 1 == 1])): ans[j] = -1
                elif grid[i][ans[j]] == 1: ans[j] += 1
                elif grid[i][ans[j]] == -1: ans[j] -= 1

        return ans


"""
RESULT: Wrong
TIME:   ms    BEAT: %    O(n) = mn
MEMORY: MB    BEAT: %    O(n) = n
Description: DP。VSCode下正确，相同的用例提交错误。似乎是BUG？
https://leetcode-cn.com/problems/where-will-the-ball-fall/solution/java-shuang-bai-di-gui-by-ethan-jx-yvx6/
"""

# class Solution:
#     def findBall(self, grid):
#         ans = []
#         row, col = len(grid), len(grid[0])

#         for i in range(len(grid[0])):
#             ans.append(i)

#         for i in range(row):
#             for j in range(col):
#                 if ans[j] == -1: continue
#                 elif grid[i][ans[j]] == 1 and ans[j] + 1 < col and grid[i][ans[j + 1]] == 1: ans[j] += 1
#                 elif grid[i][ans[j]] == -1 and ans[j] - 1 >= 0 and grid[i][ans[j - 1]] == -1: ans[j] -= 1
#                 else: ans[j] = -1

#         return ans


sol = Solution()
ans = sol.findBall([[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]])
# ans = sol.findBall([[-1]])
print(ans)