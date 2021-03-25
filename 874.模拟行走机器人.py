'''
Description: 
Version: 1.0
Autuor: Vicro
Date: 2020-11-13 17:25:01
LastEditTime: 2020-11-19 14:07:45
FilePath: \Leetcode\Chinese\874.模拟行走机器人.py
'''
#
# @lc app=leetcode.cn id=874 lang=python3
#
# [874] 模拟行走机器人
#

# @lc code=start
class Solution:
    def robotSim(self, commands, obstacles):
        direction = {'up': [0, 1, 'left', 'right'],
                     'down': [0, -1, 'right', 'left'],
                     'left': [-1, 0, 'down', 'up'],
                     'right': [1, 0, 'up', 'down']}
        x = y = 0
        dir = 'up'
        res = 0
        obstacles = set(map(tuple, obstacles))

        for command in commands:
            if command > 0:
                for step in range(command):
                    if (x + direction[dir][0], y + direction[dir][1]) not in obstacles:
                        x += direction[dir][0]
                        y += direction[dir][1]
                        res = max(res, x**2 + y**2)
            else:
                if command == -1:
                    dir = direction[dir][3]
                else:
                    dir = direction[dir][2]
        return res


sol = Solution()
A = sol.robotSim([4,-1,4,-2,4], [[2,4], [3,4]])
print(A)
# @lc code=end

