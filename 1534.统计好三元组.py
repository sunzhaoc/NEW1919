'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 14:37:28
LastEditTime: 2021-04-22 14:42:23
FilePath: \Leetcode\1534.统计好三元组.py
'''
#
# @lc app=leetcode.cn id=1534 lang=python3
#
# [1534] 统计好三元组
#

# @lc code=start
"""
RESULT: Accept
TIME:   336ms    BEAT: 92.93%    O(n) = n^3
MEMORY:  15MB    BEAT: 14.15%    O(n) = 1
USED TIME: 04:01
LAST EDIT TIME: 2021年4月22日14:42:12
Description: 
"""

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        cnt = 0
        for i in range(len(arr) - 2):
            for j in range(i + 1, len(arr) - 1):
                if abs(arr[i] - arr[j]) > a: continue
                for k in range(j + 1, len(arr)):
                    if abs(arr[i] - arr[k]) > c or abs(arr[j] - arr[k]) > b: continue
                    cnt += 1
        return cnt


# @lc code=end

