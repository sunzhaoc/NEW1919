'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-09 11:14:05
LastEditTime: 2020-12-09 13:36:41
FilePath: \Leetcode\105.从前序与中序遍历序列构造二叉树.py
'''
#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


"""
RESULT: Accept
TIME:    172ms    BEAT: 62.14%    O(n) = n
MEMORY: 85.6MB    BEAT: 30.23%    O(n) = n
Description: 上一方法的优化版本
"""

class Solution:
    def buildTree(self, preorder, inorder):
        if not preorder:    return None
        root = TreeNode(preorder[0])
        
        i = inorder.index(root.val)
        root.left = self.buildTree(preorder[1: i + 1], inorder[: i])
        root.right = self.buildTree(preorder[i + 1: ], inorder[i + 1: ])

        return root


"""
RESULT: Accept
TIME:   1060ms    BEAT: 5.16%    O(n) = 
MEMORY: 90.6MB    BEAT: 5.01%    O(n) =  
Description: 
"""

# class Solution:
#     def buildTree(self, preorder, inorder):
#         m = len(preorder)
#         if m == 0:  return None
#         root = TreeNode(preorder[0])

#         preorder_left, preorder_right, inorder_left, inorder_right = [], [], [], []

#         # 1、构建左子树的中序遍历
#         for i in range(m):
#             if (inorder[i] == preorder[0]):  break
#             inorder_left.append(inorder[i])
        
#         # 2、构建右子树的中序遍历
#         for i in range(i + 1, m):
#             inorder_right.append(inorder[i])
        
#         # 3、构建左、右子树的前序遍历
#         for j in range(1, m):
#             if j <= len(inorder_left):
#                 preorder_left.append(preorder[j])
#             else:
#                 preorder_right.append(preorder[j])
                
#         root.left = self.buildTree(preorder_left, inorder_left)
#         root.right = self.buildTree(preorder_right, inorder_right)
#         return root
        
# @lc code=end

