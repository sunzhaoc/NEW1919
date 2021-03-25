'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-02 21:35:01
LastEditTime: 2020-12-02 22:12:52
FilePath: \Leetcode\538.把二叉搜索树转换为累加树.py
'''
#
# @lc app=leetcode.cn id=538 lang=python3
#
# [538] 把二叉搜索树转换为累加树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



"""
Accept 77.64 5
中序遍历（倒序）：定义的res为int
"""
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        res = 0
        res = self.dfs(root, res)
        return root

    def dfs(self, node, res):
        if not node: return res
        res = self.dfs(node.right, res)
        res += node.val
        node.val = res
        res = self.dfs(node.left, res)
        return res


"""
Accept 31.77 13.66
中序遍历（倒序）：定义的res为列表
"""
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        res = [0]
        self.dfs(root, res)
        return root

    def dfs(self, node, res):
        if not node: return
        self.dfs(node.right, res)
        res[0] += node.val
        node.val = res[0]
        self.dfs(node.left, res)
# @lc code=end

