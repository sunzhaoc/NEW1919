'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-29 20:26:48
LastEditTime: 2020-11-29 20:31:00
FilePath: \Leetcode\515.在每个树行中找最大值.py
'''
#
# @lc app=leetcode.cn id=515 lang=python3
#
# [515] 在每个树行中找最大值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []
        self.dfs(root, 0, res)
        
        ans = []
        for i in range(len(res)):
            ans.append(max(res[i]))
        return ans
    

    def dfs(self, root, level, res):
        if not root:
            return
        if len(res) == level:
            res.append([])
        res[level].append(root.val)

        if root.left:
            self.dfs(root.left, level + 1, res)
        if root.right:
            self.dfs(root.right, level + 1, res)
# @lc code=end

