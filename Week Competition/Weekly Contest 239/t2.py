'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-05-02 11:44:05
FilePath: \Leetcode\Week Competition\Weekly Contest 239\t2.py
'''

class Solution:
    def splitString(self,s: str) -> bool:

        n=len(s)

        def dfs(idx,x):
            
            if idx==n: 
                return True
            if x==0: 
                return False


            for i in range(idx,n):
                curNum=int(s[idx: i+1])
                
                if (x-1)==curNum:
                    if dfs(i+1,curNum)==True: 
                        return True

            return False

        
        for i in range(0,n-1):

            curNum=int(s[0: i+1])

            if dfs(i+1,curNum)==True: 
                
                return True

                
        return False


# sol=Solution()
# ans=sol.
# print(ans)
