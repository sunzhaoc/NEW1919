'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-12-02 20:44:39
LastEditTime: 2020-12-02 21:11:40
FilePath: \Leetcode\136.只出现一次的数字.py
'''
#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#
import collections
# @lc code=start

"""
Accept 85.60 80.19
异或运算
https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
"""
class Solution:
    def singleNumber(self, nums):
        return reduce(lambda x, y: x ^ y, nums)


"""
Accept 52 13
哈希
"""
# class Solution:
#     def singleNumber(self, nums):
#         return collections.Counter(nums).most_common(len(nums)) [-1][0]


sol = Solution()
A = sol.singleNumber([1,2,1,2,2,4])
print(A)


# @lc code=end

