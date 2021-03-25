'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-03 10:30:34
LastEditTime: 2021-03-03 11:15:22
FilePath: \Leetcode\31.下一个排列.py
'''
#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#

# @lc code=start

"""
RESULT: Wrong
LAST EDIT TIME: 2021年3月3日11:3:20
Description: python的BUG真多。
程序直接运行报错，Leetcode上不报错。
[::-1]在Leetcode上没有用？
"""

class Solution:
    def nextPermutation(self, nums):
        if len(nums) == 1: return

        tmp = -1
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                tmp = i - 1
                break
        
        if tmp == -1:
            nums = nums[::-1]
            return
        
        for i in range(len(nums) - 1, tmp, -1):
            if nums[i] > nums[tmp]:
                nums[tmp], nums[i] = nums[i], nums[tmp]
                break

        nums[tmp + 1:] = sorted(nums[tmp + 1:])
        return



sol = Solution()
sol.nextPermutation((1,2,3,8,5,7,6,4))


# @lc code=end

