'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-01-05 14:01:16
LastEditTime: 2021-01-05 14:04:31
FilePath: \Leetcode\剑指 Offer 32 - I. 从上到下打印二叉树.py
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections


"""
RESULT: Accept
TIME:     40ms    BEAT: 69.78%    O(n) = 
MEMORY: 14.9MB    BEAT:  7.85%    O(n) = 
Description: BFS
"""

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root: return []
        res, queue = [], collections.deque()
        queue.append(root)

        while queue:
            node = queue.popleft()
            res.append(node.val)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        
        return res