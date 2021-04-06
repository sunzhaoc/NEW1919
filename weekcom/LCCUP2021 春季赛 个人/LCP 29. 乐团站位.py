'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-06 14:24:26
LastEditTime: 2021-04-06 14:25:46
FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 29. 乐团站位.py
'''

class Solution:
    def orchestraLayout(self, num: int, xPos: int, yPos: int) -> int:
        key = min(xPos, yPos, num - 1 - xPos, num - 1 - yPos)
        
        U, D, L, R = key, num - 1 - key, key, num - 1 - key
        
        cur = num**2 - (num - 2 * key)**2
        cur %= 9
        
        res = 0

        if U == xPos: 
            res = (cur + yPos - L + 1) % 9
            if res != 0: 
                return res
            else:
                return 9
        else:
            cur += (R - L + 1)
        U += 1

        if R == yPos:
            res = (cur + xPos - U + 1) % 9
            if res != 0: 
                return res
            else:
                return 9
        else:
            cur += (D - U + 1) 
        R -= 1   

        if D == xPos:
            res = (cur + R - yPos + 1) % 9
            if res != 0: 
                return res
            else:
                return 9
        else:
            cur += (R - L + 1)
        D -= 1

        if L == yPos:
            res = (cur + D - xPos + 1) % 9
            if res: 
                return res
            else: 
                return 9