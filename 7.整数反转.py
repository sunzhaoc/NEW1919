'''
@Description: 
@Version: 1.0
@Autor: Vicro
@Date: 2020-07-27 16:36:24
@LastEditors: Vicro
@LastEditTime: 2020-07-27 16:36:34
'''
#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        flag = -1 if x < 0 else 1
        x = abs(x)
        res = 0
        while x:
            res = res*10 + x%10
            x //= 10
        res *= flag
        return 0 if res<-2**31 or res>2**31-1 else res

# @lc code=end

