'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-03 23:01:36
LastEditTime: 2021-04-04 00:02:47
FilePath: \Leetcode\demo02.py
'''


class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        if len(s1) > len(s2): s1, s2 = s2, s1

        split1 = s1.split()
        split2 = s2.split()
        
        while (split1):
            if (split1[0] != split2[0] and split1[-1] != split2[-1]): return False
            if split1[0] == split2[0]: 
                split2.pop(0)
                split1.pop(0)
            else:
                split1.pop(-1)
                split2.pop(-1)
        return True