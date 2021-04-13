'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-01 21:23:43
LastEditTime: 2020-12-01 21:29:19
FilePath: \Leetcode\230.二叉搜索树中第k小的元素.py
'''
#
# @lc app=leetcode.cn id=230 lang=python3
#
# [230] 二叉搜索树中第K小的元素
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        res = []
        self.dfs(root, res)
        return res[k-1]

    def dfs(self, node, res):
        if not node:    return
        
        self.dfs(node.left, res)
        res.append(node.val)
        self.dfs(node.right, res)
# @lc code=end

