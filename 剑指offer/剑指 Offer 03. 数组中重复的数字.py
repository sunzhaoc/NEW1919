'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-03 19:13:27
LastEditTime: 2020-12-04 14:58:16
FilePath: \Leetcode\剑指 Offer 03. 数组中重复的数字.py
'''




"""
RESULT: Accept
TIME:     64ms    BEAT: 30.83%
MEMORY: 22.6MB    BEAT: 46.93%
Description: 官方解答，实际也没快多少。但使用set类型比dict类型要省空间。
"""
class Solution:
    def findRepeatNumber(self, nums):
        dict = set()
        for i in nums:
            if i in dict:
                return i
            else:
                dict.add(i)
        return -1


"""
RESULT: Accept
TIME:     60ms    BEAT: 44.55%
MEMORY: 22.9MB    BEAT: 8.40%
Description: 
"""
# class Solution:
#     def findRepeatNumber(self, nums: List[int]) -> int:
#         dict = {}
#         for i in nums:
#             if i in dict:
#                 return i
#             else:
#                 dict[i] = []


sol = Solution()
A = sol.findRepeatNumber([2, 3, 1, 0, 2, 5, 3])
print(A)