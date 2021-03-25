'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-19 16:07:19
LastEditTime: 2020-11-19 16:41:15
FilePath: \Leetcode\Chinese\406.根据身高重建队列.py
'''
#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#

# @lc code=start
class Solution:
    def reconstructQueue(self, people):
        # ------------------IMPORTANT----------------------
        people.sort(key=lambda x: (-x[0], x[1])) # 先按第一维的降序排列，再按第二维和升序排列
        # ------------------IMPORTANT----------------------
        n = len(people)
        ans = list()
        for person in people:
            # print(person[1])
            # ans[person[1]:person[1]] = [person]
            ans.insert(person[1], person)
        return ans

sol = Solution()
A = sol.reconstructQueue([[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]])
print(A)
        
# @lc code=end

