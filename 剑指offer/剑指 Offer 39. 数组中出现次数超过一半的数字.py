'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-24 15:32:00
LastEditTime: 2020-12-24 15:37:20
FilePath: \Leetcode\剑指 Offer 39. 数组中出现次数超过一半的数字.py
'''

"""
RESULT: Accept
TIME:     52ms    BEAT: 62.30%    O(n) = n
MEMORY: 15.9MB    BEAT:  9.82%    O(n) = 1
Description: 摩尔投票法。
"""

class Solution:
    def majorityElement(self, nums):
        ans, vote = 0, 0
        for i in nums:
            if vote == 0:   ans = i
            vote += 1 if ans == i else -1
        return ans


sol = Solution()
ans = sol.majorityElement([1, 2, 3, 2, 2, 2, 5, 4, 2])
print(ans)
        