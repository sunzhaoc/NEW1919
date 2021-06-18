'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-04 10:07:17
LastEditTime: 2021-04-04 14:49:06
FilePath: \Leetcode\1813.截断句子.py
'''

/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        ans = ""
        l, r = 0, 0
        cnt = 0

        while r < len(s) :
            if r == len(s) - 1 or s[r + 1] == ' ':
                ans += s[l: r + 1]
                r += 2
                l = r
                cnt += 1
                if cnt == k:
                    break
                else:
                    ans += " "
            else:
                r += 1
        
        return ans


        
sol = Solution()
ans = sol.truncateSentence("What is the solution to this problem", 4)
