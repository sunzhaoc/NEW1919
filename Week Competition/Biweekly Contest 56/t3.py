'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-04-25 10:18:37
FilePath: \Leetcode\Week Competition\Weekly Contest 238\t1.py
'''

"""
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
"""



class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)

        sumL = 0
        cntL = 0
        for i in range(n // 2):
            if num[i] == '?':                cntL += 1
            else:                sumL += int(num[i])
        sumR, cntR =0, 0
        for i in range(n//2, n):
            if num[i] == '?':                cntR += 1
            else:                sumR += int(num[i])
        
        tot_cnt = cntL + cntR
        
        if tot_cnt == 0:            return sumL != sumR
        if tot_cnt % 2 == 0:
            if cntL == cntR:    
                if sumL > sumR:                         return True
                elif sumL == sumR:                    return False    
                else:                    return True     
            elif cntL > cntR:   
                if sumL == sumR:                    return True     
                elif sumL > sumR:                    return True     
                else:       
                    if sumR - sumL < 9 * (tot_cnt - 2 * cntL) // 2:                        return True
                    if 9 * (tot_cnt - 2 * cntR) // 2 + sumL < sumR:                        return True
                    else:                        return False
            elif cntL < cntR:  
                if sumL == sumR:
                    return True
                elif sumL < sumR:
                    return True
                else:        
                    if sumL - sumR < 9 * (tot_cnt - 2 * cntL) // 2:
                        return True
                    if 9 * (tot_cnt - 2 * cntL) // 2 + sumR < sumL:
                        return True
                    else:
                        return False
        else:
            return True  