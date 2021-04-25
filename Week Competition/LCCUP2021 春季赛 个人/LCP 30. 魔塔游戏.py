'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-05 14:49:44
LastEditTime: 2021-04-06 14:33:33
FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 30. 魔塔游戏.py
'''

class Solution:
    def magicTower(self, nums: List[int]) -> int:
        n = len(nums)
        cur_sum = 0
        res = 0
        minSum = 0
        mH = []
        i = 0
        for i in range(n):
            cur_sum += nums[i]
            if nums[i] < 0:
                heapq.heappush(mH, nums[i])
            if cur_sum < 0:
                cur_min = heapq.heappop(mH)
                minSum -= cur_min;
                cur_sum -= cur_min
                res += 1
        if cur_sum < minSum:
            return -1
        return res
