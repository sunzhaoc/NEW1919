'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-01 21:32:01
LastEditTime: 2020-12-01 21:50:14
FilePath: \Leetcode\783.二叉搜索树节点最小距离.py
'''
#
# @lc app=leetcode.cn id=783 lang=python3
#
# [783] 二叉搜索树节点最小距离
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def minDiffInBST(self, root: TreeNode) -> int:
        res = []

        def dfs(node):
            if not node:    return

            dfs(node.left)
            res.append(node.val)
            dfs(node.right)

        dfs(root)
        return min([res[i + 1] - res[i] for i in range(len(res) - 1)])

"""Method 01"""
# class Solution:

#     def minDiffInBST(self, root: TreeNode) -> int:
#         res = []
#         self.dfs(root, res)

#         return min([res[i + 1] - res[i] for i in range(len(res) - 1)])
#     def dfs(self, node, res):
#         if not node:    return

#         self.dfs(node.left, res)
#         res.append(node.val)
#         self.dfs(node.right, res)
        
        

# @lc code=end

