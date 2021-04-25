'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-03-02 18:58:01
LastEditTime: 2021-03-02 19:02:02
FilePath: \Leetcode\896.单调数列.py
'''
#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#

# @lc code=start

"""
RESULT: Accept
TIME:   516ms    BEAT: 55.12%    O(n) = n
MEMORY:  21MB    BEAT: 32.03%    O(n) = 1
USED TIME: 02:57
LAST EDIT TIME: 2021年3月2日19:1:55
Description: 一次遍历。
"""

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) <= 2: return True

        U, D = True
        for i in range(1, len(A)):
            if A[i] > A[i - 1]: 
                D = False
            if A[i] < A[i - 1]:
                U = False
        return U or D

# @lc code=end

