'''
Description: :
Version: 1.0
Author: 冰凝水
Date: 2020-11-28 20:31:40
LastEditTime: 2020-11-28 21:36:46
FilePath: \Leetcode\236.二叉树的最近公共祖先.py
'''
#
# @lc app=leetcode.cn id=236 lang=python3
#
# [236] 二叉树的最近公共祖先
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None

        if root == q or root == p:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)3
        right = self.lowestCommonAncestor(root.right,p, q)
        
        if not left: return right
        if not right: return left

        return root
            
# @lc code=end

