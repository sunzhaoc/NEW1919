'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-17 22:14:25
LastEditTime: 2021-04-18 11:28:37
FilePath: \Leetcode\weekcom\Week 237\T4.py
'''



# sol = Solution()
# ans = sol.
# print(ans)
class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        res = 0

        A = []
        for x in arr2:
            res ^= x
        
        for x in arr1:
            A.append(x&res)
        
        res = 0
        for x in A:
            res ^= x

        return res