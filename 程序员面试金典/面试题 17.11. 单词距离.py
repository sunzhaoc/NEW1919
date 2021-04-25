'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-19 19:56:08
LastEditTime: 2021-04-19 20:17:01
FilePath: \Leetcode\程序员面试金典\面试题 17.11. 单词距离.py
'''

"""
RESULT: Accept
TIME:    152ms    BEAT: 44.44%    O(n) = 
MEMORY: 30.5MB    BEAT: 53.90%    O(n) = 
LAST EDIT TIME: 2021年4月19日20:17:0
Description: 
"""

class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        id1, id2 = -1, -1
        i = 0
        res = 1000000

        while id1 == -1 or id2 == -1:
            if words[i] == word1:
                id1 = i
            elif words[i] == word2:
                id2 = i
            i += 1
        
        res = abs(id1 - id2)


        while (i < len(words)):
            if id1 < id2:
                i = id1 + 1
                while i < len(words) and (words[i] != word1 or i < id2):
                    if words[i] == word1:
                        id1 = i
                        res = min(res, abs(id1 - id2))
                    i += 1
                id1 = i
                if (i < len(words) and words[i] == word1): res = min(res, abs(id1 - id2))
            elif id2 < id1:
                i = id2 + 1
                while i < len(words) and (words[i] != word2 or i < id1):
                    if words[i] == word2:
                        id2 = i
                        res = min(res, abs(id1 - id2))
                    i += 1
                id2 = i
                if (i < len(words) and words[i] == word2): res = min(res, abs(id1 - id2))
        
        return res