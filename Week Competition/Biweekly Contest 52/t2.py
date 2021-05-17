'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-05-15 23:32:46
FilePath: \Leetcode\Week Competition\Biweekly Contest 52\t2.py
'''


class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        i = 1
        while 1:
            if memory1 >= memory2:
                if memory1 >= i:
                    memory1 -= i
                    i += 1
                else:
                    return [i, memory1, memory2]
            else:
                if memory2 >= i:
                    memory2 -= i
                    i += 1
                else return [i, memory1, memory2]
        
        return -1
            

# sol = Solution()
# ans = sol.
# print(ans)
