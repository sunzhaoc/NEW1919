'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-01-04 19:50:18
LastEditTime: 2021-01-04 19:58:26
FilePath: \Leetcode\155.最小栈.py
'''
#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start


"""
RESULT: Accept
TIME:     60ms    BEAT: 96.63%    O(n) = 1
MEMORY: 17.8MB    BEAT: 17.39%    O(n) = 1
USED TIME: 05:18
Description: 双堆。
"""

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.A = []
        self.B = []

    def push(self, x: int) -> None:
        self.A.append(x)
        if (self.B == [] or x <= self.B[-1]): self.B.append(x)

    def pop(self) -> None:
        if self.A[-1] == self.B[-1]: self.B.pop()
        self.A.pop()


    def top(self) -> int:
        return self.A[-1]

    def getMin(self) -> int:
        return self.B[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

