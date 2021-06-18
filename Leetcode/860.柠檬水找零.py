'''
Description: 
Version: 1.0
Autuor: 冰凝水
Date: 2020-11-12 21:47:16
LastEditTime: 2020-11-12 22:07:13
FilePath: \Leetcode\Chinese\860.柠檬水找零.py
'''
#
# @lc app=leetcode.cn id=860 lang=python3
#
# [860] 柠檬水找零
#

# @lc code=start
class Solution:
    def lemonadeChange(self, bills):
        if bills[0] != 5:
            return False

        five, ten = 1, 0
        bills = bills[1:]
        for i in bills:
            if i == 5:
                five += 1
            if i == 10:
                if five == 0:
                    return False
                else:
                    ten += 1
                    five -= 1
            
            if i == 20:
                if ten >= 1 and five >= 1:
                    ten -= 1
                    five -= 1
                elif ten == 0 and five >= 3:
                    five -= 3
                else:
                    return False
        return True





sol = Solution()
A = sol.lemonadeChange([5,5,5,10,20])
print(A)
# @lc code=end

