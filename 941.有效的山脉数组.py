'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-01 14:42:08
LastEditTime: 2020-12-01 14:48:39
FilePath: \Leetcode\941.有效的山脉数组.py
'''
#
# @lc app=leetcode.cn id=941 lang=python3
#
# [941] 有效的山脉数组
#

# @lc code=start
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n < 3: return False
        i = 0
        while i + 1 < n - 1 and arr[i] < arr[i + 1]:
            i += 1
        
        if i == 0: return False

        while i + 1 < n and arr[i] > arr[i + 1]:
            i += 1
            
        if i == n - 1:
            return True
        return False
# @lc code=end

