'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-06 14:24:26
LastEditTime: 2021-04-06 15:13:03
FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 29. 乐团站位.py
'''

class Solution:
    def orchestraLayout(self, num: int, xPos: int, yPos: int) -> int:
        #key = min(xPos, yPos)
        key = min(xPos, yPos, num-1-xPos, num-1-yPos)
        
        up = key            #上
        down = num-1-key    #下
        left = key          #左
        right = num-1-key   #右
        
        cur = num**2 - (num-2*key)**2
        cur %= 9
        
        res = 0
        ######情况1
        if up == xPos:      #如果上，是行号
            res = (cur + yPos - left + 1) % 9
            return res if res!=0 else 9
        else:
            cur += (right - left + 1)   #右-左+1 （步长）

        up += 1         #下移一行
        ######情况2
        if right == yPos:   #如果右是列号
            res = (cur + xPos - up + 1) % 9
            return res if res!=0 else 9
        else:
            cur += (down - up + 1)      #下-上+1 （步长）
        
        right -= 1      #左移一列
        ######情况3
        if down == xPos:
            res = (cur + right - yPos + 1) % 9
            return res if res!=0 else 9
        else:
            cur += (right - left + 1)   #左-右+1 （步长）
        
        down -= 1   #上移一行
        ######情况4
        if left == yPos:
            res = (cur + down - xPos + 1) % 9
            return res if res else 9
