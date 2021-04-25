'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-03 20:11:05
LastEditTime: 2020-12-03 20:22:47
FilePath: \Leetcode\剑指 Offer 06. 从尾到头打印链表.py
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


"""
RESULT: Accept
TIME: 56ms BEAT: 37.52%
MEMORY: 15MB BEAT: 43.29%
Description: 
"""
# class Solution:
#     def reversePrint(self, head: ListNode) -> List[int]:
#         res = []
#         while head:
#             res.append(head.val)
#             head = head.next
#         return res[::-1]


"""
RESULT: Accept
TIME: 40ms BEAT: 92.69%
MEMORY: 25.5MB BEAT: 5.04%
Description: 递归方法
"""
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        
        def function(node):
            if not node: return
            res.append(node.val)
            function(node.next)
            
        res = []
        function(head)
        return res[::-1]