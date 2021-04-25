'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-25 11:00:36
LastEditTime: 2020-12-25 11:15:36
FilePath: \Leetcode\剑指 Offer 09. 用两个栈实现队列.py
'''

"""
RESULT: Accept
TIME:    400ms    BEAT: 96.04%    O(n) = 
MEMORY: 18.3MB    BEAT: 10.15%    O(n) = 
Description: 
"""

class CQueue:

    def __init__(self):
        self.A = []
        self.B = []

    def appendTail(self, value: int) -> None:
        self.A.append(value)

    def deleteHead(self) -> int:
        if self.B:  return self.B.pop()
        if not self.A:  return -1
        while self.A:
            self.B.append(self.A.pop())
        return self.B.pop()




# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()