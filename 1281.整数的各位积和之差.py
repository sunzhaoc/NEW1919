'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-19 14:17:55
LastEditTime: 2020-11-19 15:09:38
FilePath: \Leetcode\Chinese\1281.整数的各位积和之差.py
'''
#
# @lc app=leetcode.cn id=1281 lang=python3
#
# [1281] 整数的各位积和之差
#

# @lc code=start
class Solution:
    def subtractProductAndSum(self, groupSizes):
        group = {}
        for i, _id in enumerate(groupSizes):
            # i - i-th people
            # _id - in which group
            if _id in group.keys():
                group[_id].append(i)
            else:
                group[_id] = [i]
        
        ans = list()
        for i in group:      
            # Select each group:
            for j in range(len(group[i])//i):
                # Select people
                ans.append(group[i][(j+1)*i-1-(i-1):(j+1)*i])
        return ans


sol = Solution()
A = sol.subtractProductAndSum([2, 1, 3, 3, 3, 2])
print(A)

# @lc code=end

