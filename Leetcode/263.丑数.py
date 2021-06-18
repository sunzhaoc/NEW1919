#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#

# @lc code=start

"""
RESULT: Accept
TIME:     44ms    BEAT: 50.10%    O(n) = 
MEMORY: 14.7MB    BEAT: 87.47%    O(n) = 
LAST EDIT TIME: 2021年4月10日14:45:51
Description: 
"""

class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0: return False
        nums = [2 ,3 ,5]
        for num in nums:
            while n % num == 0: n /= num
        return n == 1
# @lc code=end

