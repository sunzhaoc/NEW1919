'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-11-12 22:11:16
LastEditTime: 2020-11-12 22:35:11
FilePath: \Leetcode\Chinese\944.删列造序.py
'''
#
# @lc app=leetcode.cn id=944 lang=python3
#
# [944] 删列造序
#

# @lc code=start
class Solution:
    def minDeletionSize(self, A):
        ans = 0
        
        for col in zip(*A):
            if sorted(col) != list(col):
                ans += 1;            
        return ans    


sol = Solution()
A = sol.minDeletionSize(["cba","daf","ghi"])
print(A)
# @lc code=end

