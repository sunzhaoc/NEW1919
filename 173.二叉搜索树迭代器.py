'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-01 17:05:35
LastEditTime: 2020-12-01 20:26:03
FilePath: \Leetcode\173.二叉搜索树迭代器.py
'''
#
# @lc app=leetcode.cn id=173 lang=python3
#
# [173] 二叉搜索树迭代器
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator:

    def __init__(self, root: TreeNode):
        res = []
        self.dfs(root, res)
        self.list = res
        self.point = -1

    def dfs(self, root, res):
        if not root: return

        self.dfs(root.left, res)
        res.append(root.val)
        self.dfs(root.right, res)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.point += 1
        return self.list[self.point]


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.point < len(self.list) - 1



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

