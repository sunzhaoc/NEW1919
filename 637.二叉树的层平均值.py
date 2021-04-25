'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-29 20:00:02
LastEditTime: 2020-11-29 20:17:59
FilePath: \Leetcode\637.二叉树的层平均值.py
'''
#
# @lc app=leetcode.cn id=637 lang=python3
#
# [637] 二叉树的层平均值
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        res = []
        self.dfs(root, 0, res)
        
        ans = []
        for i in range(len(res)):
            sum = 0.0 
            for j in range(len(res[i])):
                sum += res[i][j]
            ans.append(sum/len(res[i]))
            
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

