'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-26 15:24:51
LastEditTime: 2020-11-26 17:21:50
FilePath: \Leetcode\738.单调递增的数字.py
'''
#
# @lc app=leetcode.cn id=738 lang=python3
#
# [738] 单调递增的数字
#

# @lc code=start
class Solution:
    def monotoneIncreasingDigits(self, N):
        if N < 10:
            return N
        M = str(N)
        length = len(M)
        
        index, num = 0, M[0]
        for i in range(1, length):
            if M[i] > M[i - 1]:
                index, num = i, int(M[i])
            if M[i] < M[i - 1]:
                ans = M[:index] + str(int(M[index]) - 1) + '9' * (length - index - 1)
                return int(ans)
        return N

        

sol = Solution()
A = sol.monotoneIncreasingDigits(332)
print(A)
# @lc code=end

