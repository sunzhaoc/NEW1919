'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-22 09:56:44
LastEditTime: 2021-04-22 10:00:33
FilePath: \Leetcode\760. 找出变位映射.py
'''

"""
RESULT: Accept
TIME:   40ms    BEAT: 76.92%    O(n) = 
MEMORY: 15MB    BEAT:  5.77%    O(n) = 
USED TIME: 02:55
LAST EDIT TIME: 2021年4月22日10:0:18
Description: 
"""

class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        dic = defaultdict(int)
        for i in range(len(B)):
            dic[B[i]] = i
        res = []
        for x in A:
            res.append(dic[x])
        return res
            