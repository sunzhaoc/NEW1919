'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-01-10 10:28:49
LastEditTime: 2021-01-10 10:44:30
FilePath: \Leetcode\demo01.py
'''
class Solution:
    def decode(self, encoded, first):
        res = [first]
        for i in range(len(encoded)):
            res.append(encoded[i] ^ res[-1])

        return res        
sol = Solution()
# ans = sol.decode([6, 2, 7, 3], 4)
ans = sol.decode([1, 2, 3], 1)
print(ans)