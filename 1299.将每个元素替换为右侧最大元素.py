'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 16:00:47
LastEditTime: 2021-04-22 16:03:19
FilePath: \Leetcode\1299.将每个元素替换为右侧最大元素.py
'''
#
# @lc app=leetcode.cn id=1299 lang=python3
#
# [1299] 将每个元素替换为右侧最大元素
#

# @lc code=start
"""
RESULT: Accept
TIME:   60ms    BEAT: 65.58%    O(n) = 
MEMORY: 16MB    BEAT: 28.47%    O(n) = 
USED TIME: 02:02
LAST EDIT TIME: 2021年4月22日16:3:3
Description: 
"""

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        n = len(arr)
        res = [0] * (n - 1) + [-1]
        for i in range(n - 2, -1, -1):
            res[i] = max(res[i + 1], arr[i + 1])
        return res

# @lc code=end

