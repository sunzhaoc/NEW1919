'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-29 17:16:46
LastEditTime: 2020-11-29 17:26:25
FilePath: \Leetcode\199.二叉树的右视图.py
'''
#
# @lc app=leetcode.cn id=199 lang=python3
#
# [199] 二叉树的右视图
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        self.dfs(root, 0, res)
        ans = []
        for i in range(len(res)):
            ans.append(res[i][-1])
        return ans
        
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

