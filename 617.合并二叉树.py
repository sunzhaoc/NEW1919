'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-27 12:16:56
LastEditTime: 2020-11-27 12:21:01
FilePath: \Leetcode\617.合并二叉树.py
'''
#
# @lc app=leetcode.cn id=617 lang=python3
#
# [617] 合并二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1:
            return t2
        if not t2:
            return t1
        
        meregd = TreeNode(t1.val + t2.val)
        meregd.left = self.mergeTrees(t1.left, t2.left)
        meregd.right = self.mergeTrees(t1.right, t2.right)
        return meregd
        
# @lc code=end

