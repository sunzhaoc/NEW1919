'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-03-02 16:06:37
LastEditTime: 2021-03-02 16:13:06
FilePath: \Leetcode\11.盛最多水的容器.py
'''
#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#

# @lc code=start

"""
RESULT: Accept
TIME:    112ms    BEAT:  5.87%    O(n) = n
MEMORY: 16.1MB    BEAT: 61.35%    O(n) = 1
LAST EDIT TIME: 2021年3月2日16:13:6
Description: 双指针。
"""

class Solution:
    def maxArea(self, height: List[int]) -> int:
        L, R = 0, len(height) - 1
        ans = -1
        while L < R: 
            ans = max(ans, min(height[L], height[R]) * (R - L))
            if height[L] > height[R]:
                R -= 1
            else:
                L += 1
        return ans

# @lc code=end

