#
# @lc app=leetcode.cn id=1450 lang=python3
#
# [1450] 在既定时间做作业的学生人数
#

# @lc code=start
"""
RESULT: Accept
TIME:     40ms    BEAT: 62.09%    O(n) = 
MEMORY: 14.8MB    BEAT: 84.86%    O(n) = 
USED TIME: 01:05
LAST EDIT TIME: 2021年4月22日14:3:41
Description: 
"""

class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        cnt = 0
        for i in range(len(startTime)):
            if queryTime >= startTime and queryTime <= endTime:
                cnt += 1
        return cnt
# @lc code=end

