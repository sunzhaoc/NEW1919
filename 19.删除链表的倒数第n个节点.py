'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-02 18:24:49
LastEditTime: 2021-03-02 18:30:29
FilePath: \Leetcode\19.删除链表的倒数第n个节点.py
'''
#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
RESULT: Accept
TIME:     48ms    BEAT: 22.90%    O(n) = n
MEMORY: 14.8MB    BEAT: 38.88%    O(n) = 1
LAST EDIT TIME: 2021年3月2日18:30:31
Description: 
"""

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node = ListNode(0)
        node.next = head

        slow, fast = node, node
        for _ in n:
            fast = fast.next
        
        while fast and fast.next:
            slow, fast = slow.next, fast.next
        
        slow.next = slow.next.next
        return node.next

# @lc code=end

