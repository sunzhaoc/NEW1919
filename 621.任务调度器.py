'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-25 18:53:55
LastEditTime: 2020-11-26 15:09:32
FilePath: \Leetcode\621.任务调度器.py
'''
#
# @lc app=leetcode.cn id=621 lang=python3
#
# [621] 任务调度器
#

# @lc code=start
from collections import Counter

class Solution:
    def leastInterval(self, tasks, n):
        
        if len(tasks) <= 1:
            return len(tasks)

        temp = list(set(tasks))
        num = []
        for i in temp:
            num.append(tasks.count(i))
        num.sort(key=lambda x: -x)
        
        time = (num[0] - 1) * (n + 1) + 1

        for i in num[1:]:
            if i == num[0]:
                time += 1
        
        return time if time >= len(tasks) else len(tasks)


sol = Solution()
A = sol.leastInterval(["A","A","A","B","B",""], 2)
print(A)
# @lc code=end

