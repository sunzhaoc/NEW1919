'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-01 16:12:46
LastEditTime: 2020-12-01 16:15:29
FilePath: \Leetcode\94.二叉树的中序遍历.py
'''
#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        self.dfs(root, res)

        return res
        
    def dfs(self, node, res):
        if not node: return
        self.dfs(node.left, res)
        res.append(node.val)
        self.dfs(node.right, res)

# @lc code=end

