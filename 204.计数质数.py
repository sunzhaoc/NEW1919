'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-03 18:05:17
LastEditTime: 2020-12-03 18:37:21
FilePath: \Leetcode\204.计数质数.py
'''
#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#

# @lc code=start
class Solution:
    def countPrimes(self, n):
        if n < 2:   return 0

        list = [1] * n
        list[0] = list[1] = 0 

        for i in range(2, int(n ** 0.5) + 1):
            if(list[i]):
                j = i
                while j * i < n:
                    list[j * i] = 0
                    j += 1

        return sum(list)
            
            
sol = Solution()
A = sol.countPrimes(10)
print(A)
# @lc code=end

