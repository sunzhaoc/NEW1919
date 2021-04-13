'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-23 21:01:55
LastEditTime: 2020-12-23 21:35:41
FilePath: \Leetcode\111.二叉树的最小深度.py
'''
#
# @lc app=leetcode.cn id=111 lang=python3
#
# [111] 二叉树的最小深度
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
TIME:    648ms    BEAT: 16.24%    O(n) = N
MEMORY: 55.4MB    BEAT:  7.24%    O(n) = H
Description: DFS
"""

class Solution:
    def minDepth(self, root):
        if not root:    return 0
        if not root.left and not root.right:    return 1

        depth1 = self.minDepth(root.left)
        depth2 = self.minDepth(root.right)

        if not root.left or not root.right: return depth1 + depth2 + 1
        return min(depth1, depth2) + 1        

# @lc code=end

