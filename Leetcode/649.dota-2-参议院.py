'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-24 22:14:25
LastEditTime: 2020-11-25 19:32:06
FilePath: \Leetcode\649.dota-2-参议院.py
'''
#
# @lc app=leetcode.cn id=649 lang=python3
#
# [649] Dota2 参议院
#

# @lc code=start
class Solution:
    def predictPartyVictory(self, senate):
        senate = list(senate)
        R, D = True, True
        person = 0
        while R and D:
            R, D = False, False
            for i in range(len(senate)):
                if senate[i] == "R":
                    R = True
                    if person < 0:
                        senate[i] = "0"
                    person += 1
                elif senate[i] == "D":
                    D = True
                    if person > 0:
                        senate[i] = "0"
                    person -= 1

        if person > 0:
            return "Radiant"
        else:
            return "Dire"


sol = Solution()
A = sol.predictPartyVictory("DDRRR")
print(A)
        
# @lc code=end

