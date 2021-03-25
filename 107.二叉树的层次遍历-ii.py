'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-29 16:58:57
LastEditTime: 2020-11-29 17:11:38
FilePath: \Leetcode\107.二叉树的层次遍历-ii.py
'''
#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层次遍历 II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        self.dfs(root, 0, res)
        return res[::-1]

    def dfs(self, root, level, res):
        if not root: return
        if len(res) == level:
            res.append([])
        res[level].append(root.val)
        if root.left:
            self.dfs(root.left, level + 1, res)
        if root.right:
            self.dfs(root.right, level + 1, res)
        
# @lc code=end

