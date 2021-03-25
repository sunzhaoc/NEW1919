'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-29 20:18:54
LastEditTime: 2020-11-29 20:25:36
FilePath: \Leetcode\429.n叉树的层序遍历.py
'''
#
# @lc app=leetcode.cn id=429 lang=python3
#
# [429] N叉树的层序遍历
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        self.dfs(root, 0, res)
        return res
    
    
    def dfs(self, root, level, res):
        if not root: return
        if len(res) == level:
            res.append([])
        res[level].append(root.val)
        
        for child in root.children:
            if child:
                self.dfs(child, level + 1, res)
        
# @lc code=end

