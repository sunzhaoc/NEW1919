'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-19 21:55:25
LastEditTime: 2020-11-19 22:50:45
FilePath: \Leetcode\Chinese\134.加油站.py
'''
#
# @lc app=leetcode.cn id=134 lang=python3
#
# [134] 加油站
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas, cost):
        # Choose one gas station to begin:
        for i in range(len(gas)):
            V = 0

            if i == 0:
                gas_temp = gas
                cost_temp = cost
            else:
                gas_temp = gas[i:] + gas[0: i]
                cost_temp = cost[i:] + cost[0: i]
            
            for j in range(len(gas_temp)):
                V += gas_temp[j]
                if V >= cost_temp[j]:
                    V -= cost_temp[j]
                    if j == len(gas_temp) - 1:
                        return i
                else:
                    break
                
        return -1


class Solution2:
    def canCompleteCircuit(self, gas, cost):
        # total记录可获得的总油量-总油耗， cur记录当前油耗情况， ans记录出发位置
        total, cur, ans = 0, 0, 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            cur += gas[i] - cost[i]
            if cur < 0:                     # 油不够开到i站
                cur = 0                     # cur置零，在新位置重新开始计算油耗情况
                ans = i + 1                 # 将起始位置改成i+1
        return ans if total >= 0 else -1    # 如果获得的汽油的量小于总油耗，则无法环
                                            # 行一周返回 -1；反之返回ans

        
sol = Solution2()
A = sol.canCompleteCircuit([1,2,3,4,5], [3,4,5,1,2])
print(A)
# @lc code=end

