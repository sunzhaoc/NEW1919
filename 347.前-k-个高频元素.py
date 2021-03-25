'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-02 16:48:47
LastEditTime: 2020-12-02 19:24:30
FilePath: \Leetcode\347.前-k-个高频元素.py
'''
#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
import collections

"""Others - 01"""
# class Solution:
#     def topKFrequent(self, nums, k):
#         return [i[0] for i in collections.Counter(nums).most_common(k)]


"""Write by myself -- BEAT: 93.81 and 33.05"""
# class Solution:
#     def topKFrequent(self, nums, k):
#         stat = collections.Counter(nums)

#         stat = list(stat.items())
#         stat = sorted(stat, key=lambda x: -x[1])

#         ans = []
#         i = 0
#         while len(ans) != k:
#             ans.append(stat[i][0])
#             i += 1
        
#         return ans
        

"""Time Out, Code is right"""
# class Solution:
#     def topKFrequent(self, nums, k):
#         nums = sorted(nums, key=lambda x: -nums.count(x))
#         print("AAA")
#         ans = []
#         for i in nums:
#             if i not in ans:
#                 ans.append(i)
#             if len(ans) == k:
#                 break
#         return ans


sol = Solution()
A = sol.topKFrequent([1,1,1,2,2,3, 4, 4, 4 ,4 ], 2)
print(A)
# @lc code=end

