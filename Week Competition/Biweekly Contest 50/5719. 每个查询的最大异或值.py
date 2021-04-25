'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-17 22:14:25
LastEditTime: 2021-04-17 23:09:52
FilePath: \Leetcode\weekcom\Double Week 50\T3.py
'''



# sol = Solution()
# ans = sol.
# print(ans)


class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        A = []
        A.append(nums[0])

        for i in range(1, n):
            A[i] = A[i - 1] ^ nums[i]

        res = []
        for x in A[::-1]:
            res.append(2 ** maximumBit - 1 - x)
        
        return res
        