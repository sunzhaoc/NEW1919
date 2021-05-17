'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-05-15 23:30:51
FilePath: \Leetcode\Week Competition\Biweekly Contest 52\t1.py
'''
class Solution:
    def sortSentence(self, s: str) -> str:
        words = list(s.split())
        dic = dict()
        for word in words:
            wo = word[:-1]
            id = int(word[-1])
            dic[id] = wo
        
        ans = []
        tmpS = list(dic.items())
        tmpS.sort(key=lambda x: x[0])
        for idx, wo in tmpS:
            ans.append(wo)
        return ' '.join(ans)



# sol = Solution()
# ans = sol.
# print(ans)
