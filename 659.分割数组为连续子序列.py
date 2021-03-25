'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-04 13:18:25
LastEditTime: 2021-03-01 19:47:32
FilePath: \Leetcode\659.分割数组为连续子序列.py
'''
#
# @lc app=leetcode.cn id=659 lang=python3
#
# [659] 分割数组为连续子序列
#

# @lc code=start

"""
RESULT: Accept
TIME: 144ms BEAT: 77%
MEMORY: 14.6MB BEAT: 42%
Description: 
"""
class Solution:
    def isPossible(self, nums):
        dict = {}
        for i in nums:
            if i not in dict.keys():
                dict[i] = 1
            else:
                dict[i] += 1
        tail = {}
        
        for i in nums:
            if dict[i] == 0: continue
            if (i - 1) in tail.keys() and tail[i - 1] > 0 and dict[i] > 0:
                dict[i] -= 1
                tail[i - 1] -= 1
                if i in tail.keys():
                    tail[i] += 1
                else:
                    tail[i] = 1
            elif (i in dict.keys() and (i + 1) in dict.keys() and (i + 2) in dict.keys()) and dict[i] > 0 and dict[i + 1] > 0 and dict[i + 2] > 0:
                dict[i] -= 1
                dict[i + 1] -= 1
                dict[i + 2] -= 1
                if (i + 2) in tail.keys():
                    tail[i + 2] += 1
                else: 
                    tail[i + 2] = 1
            else: return False
        return True


sol = Solution()
A = sol.isPossible([1,2,5,5,6,6,7,8,8,9])
print(A)

# @lc code=end

