'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-04-25 10:18:37
FilePath: \Leetcode\Week Competition\Weekly Contest 238\t1.py
'''


class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        for i in range(len(dist)):
            dist[i] = int(int(dist[i] + speed[i] - 1) / speed[i])
        sorted(dist)
        if dist[0] == 0: return 0
        cnt = 1
        for i in range(1, len(dist)):
            if dist[i] <= i: return cnt
            else: cnt += 1
        return cnt

# sol = Solution()
# ans = sol.
# print(ans)
