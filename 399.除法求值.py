'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-01-06 09:34:58
LastEditTime: 2021-01-06 13:40:17
FilePath: \Leetcode\399.除法求值.py
'''
#
# @lc app=leetcode.cn id=399 lang=python3
#
# [399] 除法求值
#

# @lc code=start


"""
RESULT: Accept
TIME:     44ms    BEAT: 27.53%    O(n) = 
MEMORY: 14.9MB    BEAT: 11.39%    O(n) = 
Description: 
"""

class XreeNode:
    def __init__(self, x):
        self.val = None
        self.weight = [1.0] * x
        self.parent = []
        for i in range(x):
            self.parent.append(i)

    def union(self, x, y, value):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY: return
        self.parent[rootX] = rootY
        self.weight[rootX] = self.weight[y] * value / self.weight[x]

    # 路径压缩
    def find(self, x):
        if x != self.parent[x]:
            origin = self.parent[x]
            self.parent[x] = self.find(self.parent[x])
            self.weight[x] *= self.weight[origin]
        return self.parent[x]

    def isConected(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return self.weight[x] / self.weight[y]
        else:
            return -1


class Solution:
    def calcEquation(self, equations, values, queries):
        equations_Size = len(equations)
        
        node = XreeNode(2 * equations_Size)
        id = 0
        hashMap = {}

        for i in range(equations_Size):
            if equations[i][0] not in hashMap.keys():
                hashMap[equations[i][0]] = id
                id += 1
            if equations[i][1] not in hashMap.keys(): 
                hashMap[equations[i][1]] = id
                id += 1
            node.union(hashMap[equations[i][0]], hashMap[equations[i][1]], values[i])
        
        queries_Size = len(queries)
        res = [None] * queries_Size

        for i in range(queries_Size):
            id1 = hashMap.get(queries[i][0])
            id2 = hashMap.get(queries[i][1])

            if id1 == None or id2 == None:
                res[i] = -1.0
            else:
                res[i] = node.isConected(id1, id2)
            
        return res


sol = Solution()
# ans = sol.calcEquation([["a","b"],["b","c"]], [2.0,3.0], [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]])
# ans = sol.calcEquation([["a","b"],["b","c"],["bc","cd"]], [1.5,2.5,5.0], [["a","c"],["c","b"],["bc","cd"],["cd","bc"]])
# ans = sol.calcEquation(equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]])
ans = sol.calcEquation([["a","b"],["e","f"],["b","e"]], [3.4,1.4,2.3], [["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]])
print(ans)

# @lc code=end

