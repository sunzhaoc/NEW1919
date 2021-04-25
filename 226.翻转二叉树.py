'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-27 22:14:29
LastEditTime: 2020-11-27 22:23:05
FilePath: \Leetcode\226.翻转二叉树.py
'''
#
# @lc app=leetcode.cn id=226 lang=python3
#
# [226] 翻转二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left, root.right = right, left
        return root
        
# @lc code=end

