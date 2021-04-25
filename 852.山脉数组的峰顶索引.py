'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2020-10-04 20:30:17
FilePath: /Leetcode/Chinese/852.山脉数组的峰顶索引.py
'''
#
# @lc app=leetcode.cn id=852 lang=python3
#
# [852] 山脉数组的峰顶索引
#

# @lc code=start
class Solution:
    def peakIndexInMountainArray(self, arr):
        l, r = 1, len(arr) - 1
        
        while l < r:
            mid = (r - l) // 2 + l;
            
            if (arr[mid] > arr[mid-1]) and (arr[mid] > arr[mid+1]):
                return mid
            elif arr[mid] > arr[mid - 1]:
                l = mid + 1
            else:
                r = mid
                
        return l
# @lc code=end

