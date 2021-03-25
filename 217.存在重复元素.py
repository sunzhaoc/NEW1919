#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
import collections


"""
RESULT: Accept
TIME:     64ms    BEAT: 7.92%    O(n) = 
MEMORY: 23.5MB    BEAT: 5.36%    O(n) =  
Description: 
"""

class Solution:
    def containsDuplicate(self, nums):
        if nums == []:   return False
        if collections.Counter(nums).most_common() [0][1] > 1:
            return True
        return False


sol = Solution()
A = sol.containsDuplicate([1, 2, 3, 1])
print(A)
# @lc code=end

