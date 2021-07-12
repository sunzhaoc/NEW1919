'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-04-25 10:18:37
FilePath: \Leetcode\Week Competition\Weekly Contest 238\t1.py
'''



class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m = len(maze)
        n = len(maze[0])
        
        aa, bb = entrance[0], entrance[1]
        maze[aa][bb] = '+'
        
        Q = collections.deque()
        for nr, nc in [[aa-1,bb], [aa+1,bb], [aa, bb-1], [aa,bb+1]]:
            if 0 <= nr < m and 0 <= nc < n:
                if maze[nr][nc] == '.':
                    maze[nr][nc] = '+'
                    Q.append([nr, nc])
        step = 0
        while Q:
            step += 1
            for _ in range(len(Q)):
                r, c = Q.popleft()
                # print("{} {}".format(r, c))
                if r in (0, m - 1) or c in (0, n - 1):
                    return step
                
                for nr, nc in [[r-1,c], [r+1,c], [r, c-1], [r,c+1]]:
                    if 0 <= nr < m and 0 <= nc < n:
                        if maze[nr][nc] == '.':
                            maze[nr][nc] = '+'
                            Q.append([nr, nc])
        
        return -1

# sol = Solution()
# ans = sol.
# print(ans)
