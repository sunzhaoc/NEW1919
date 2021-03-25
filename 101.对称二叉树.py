'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-02 19:50:47
LastEditTime: 2020-12-02 20:40:31
FilePath: \Leetcode\101.对称二叉树.py
'''
#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Accept 67.12 17.64
递归
https://leetcode-cn.com/problems/symmetric-tree/solution/di-gui-die-dai-bi-xu-miao-dong-by-sweetiee/
"""
# class Solution:
#     def isSymmetric(self, root: TreeNode) -> bool:
#         if not root: return True
        
#         return self.cmp(root.left, root.right)
        
#     def cmp(self, node1, node2):
#         if not node1 and not node2: return True
#         if not node1 or not node2 or node1.val != node2.val:    return False
        
#         return self.cmp(node1.left, node2.right) and self.cmp(node1.right, node2.left)
        

"""
Accept 68 19
层次遍历
"""
# class Solution:
#     def isSymmetric(self, root: TreeNode) -> bool:
#         res = []
#         self.dfs(root, 0, res)            
#         for i in (res):
#             if not self.whether_symmetry(i):
#                 return False
            
#         return True

#     def whether_symmetry(self, list):
#         n = len(list)
#         for i in range(n):
#             if list[i] != list[n - 1 - i]:  return False
#         return True
    
#     def dfs(self, node, level, res):
#         if not node:
#             res[level].append(None)
#         if len(res) == level:
#             res.append([])
#         res[level].append(node.val)
#         if node.left:
#             self.dfs(node.left, level + 1, res)
#         if node.right:
#             self.dfs(node.right, level + 1, res)
        
        
# @lc code=end

