'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-01-07 09:25:54
LastEditTime: 2021-01-07 10:00:15
FilePath: \Leetcode\547.省份数量.py
'''

"""
RESULT: Accept
TIME:     56ms    BEAT: 71.07%    O(n) = 
MEMORY: 15.1MB    BEAT: 13.01%    O(n) = 
Description: 并查集。
"""

class Solution:
    def findCircleNum(self, isConnected):
        def find(index):
            if parent[index] != index:
                parent[index] = find(parent[index])
            return parent[index]
        
        def union(index1, index2):
            parent[find(index1)] = find(index2)

        provinces = len(isConnected) # 城市数
        parent = list(range(provinces))

        for i in range(provinces):
            for j in range(i + 1, provinces):
                if isConnected[i][j] == 1:
                    union(i, j)

        circles = sum(parent[i] == i for i in range(provinces))
        return circles


sol = Solution()
ans = sol.findCircleNum( [[1,1,0],[1,1,0],[0,0,1]])
print(ans)