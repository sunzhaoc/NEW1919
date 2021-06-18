'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 1970-01-01 08:00:00
LastEditTime: 2021-06-14 13:07:54
FilePath: \Leetcode\374.猜数字大小.py
'''
#
# @lc app=leetcode.cn id=374 lang=python3
#
# [374] 猜数字大小
#

# @lc code=start
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:
"""
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
"""

"""
RESULT: Accept
TIME:     36ms    BEAT: 84.47%    O(n) = 
MEMORY: 14.8MB    BEAT: 64.74%    O(n) = 
LAST EDIT TIME: 2021年6月14日13:7:28
Description: 
"""

class Solution:
    def guessNumber(self, n: int) -> int:
        l, r = 1, n
        while l <= r:
            mid= (r + l) // 2
            if guess(mid) == 0: return mid
            if guess(mid) == -1: r = mid- 1
            else: l = mid + 1
        return -1


class Solution:
    def guessNumber(self, n):
        l, r = 1, n
        while l < r:
            mid = (r - l) // 2 + l
            if guess(mid) == 0:
                return mid
            elif guess(mid) == -1:
                r = mid
            else:
                l = mid + 1
        return l


# @lc code=end

