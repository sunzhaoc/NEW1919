'''
@Description: 
@Version: 1.0
@Autor: Vicro
@Date: 2020-07-27 15:28:58
@LastEditors: Vicro
@LastEditTime: 2020-07-27 15:30:03
'''
#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x>=0:
            y = str(x)
            z = y[::-1]
            num = len(y)//2 if len(y)%2==0 else (len(y)-1)//2
            for i in range(num):
                if y[i] != z[i]:
                    return False
            return True
        else:
            return False
# @lc code=end

