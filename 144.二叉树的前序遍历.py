'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-01-07 15:31:31
LastEditTime: 2021-01-07 15:35:59
FilePath: \Leetcode\144.二叉树的前序遍历.py
'''
#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] 二叉树的前序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


"""
RESULT: Accept
TIME:     36ms    BEAT: 79.78%    O(n) = 
MEMORY: 14.5MB    BEAT: 11.60%    O(n) = 
USED TIME: 
Description: 
"""

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        def dfs(node):
            if not node: return
            res.append(node.val)
            dfs(node.left)
            dfs(node.right)
        
        res = []
        dfs(root)
        return res
# @lc code=end

