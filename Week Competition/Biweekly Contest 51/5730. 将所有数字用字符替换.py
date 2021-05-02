'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-04-25 10:18:37
FilePath: \Leetcode\Week Competition\Weekly Contest 238\t1.py
'''

class Solution:
    def replaceDigits(self, s: str) -> str:
        n = len(s)
        s=list(s)
        
        for i in range(1,n,2):
            s[i]=chr(int(s[i])+ord(s[i - 1]))
            
        return ''.join(s)


# sol = Solution()
# ans = sol.
# print(ans)
