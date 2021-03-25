'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-29 21:37:06
LastEditTime: 2020-11-29 21:37:10
FilePath: \Leetcode\117.填充每个节点的下一个右侧节点指针-ii.py
'''
#
# @lc app=leetcode.cn id=117 lang=python3
#
# [117] 填充每个节点的下一个右侧节点指针 II
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        res = []
        self.dfs(root, 0, res)

        for i in range(len(res)):
            for j in range(len(res[i])):
                if j != len(res[i])-1:
                    res[i][j].next = res[i][j + 1]
        return root 
        
    def dfs(self, root, level, res):
        if not root: return
        if len(res) == level:
            res.append([])
        res[level].append(root)
        if root.left:
            self.dfs(root.left, level + 1, res)
        if root.right:
            self.dfs(root.right, level + 1, res)
# @lc code=end

