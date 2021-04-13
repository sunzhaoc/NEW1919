'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-01 13:53:15
LastEditTime: 2020-12-01 13:57:03
FilePath: \Leetcode\349.两个数组的交集.py
'''
#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#

# @lc code=start
class Solution:
    # def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
    def intersection(self, nums1, nums2):
        nums1 = list(set(nums1))
        nums2 = list(set(nums2))

        ans = []
        for i in nums1:
            if i in nums2:
                ans.append(i)
        return ans


import time
start = time.time()
sol = Solution()
A = sol.intersection([1,2,2,1], [2,2])
print(A)

print((time.time() - start)*1000, "ms")
# @lc code=end

