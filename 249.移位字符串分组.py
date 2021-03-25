'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-03 16:43:15
LastEditTime: 2021-03-03 17:04:23
FilePath: \Leetcode\249.移位字符串分组.py
'''



"""
RESULT: Accept
TIME:     52ms    BEAT: 13.27%    O(n) = 
MEMORY: 15.1MB    BEAT: 14.41%    O(n) = 
USED TIME: 20:00
LAST EDIT TIME: 2021年3月3日17:4:4
Description: UGLY CODE。
"""

class Solution:
    def groupStrings(self, strings):
        dict = {}

        for strs in strings:
            if len(strs) == 1:
                if "-1" in dict.keys():
                    dict["-1"].append(strs)
                else:
                    dict["-1"] = [strs]
            else:
                tmp = ""
                for i in range(1, len(strs)):
                    A, B = ord(strs[i]), ord(strs[i - 1])
                    tmp += str(26 + A - B if A - B < 0 else A - B)
                    tmp += " "
                if tmp in dict.keys():
                    dict[tmp].append(strs)
                else:
                    dict[tmp] = [strs]
        
        return [dict[x] for x in dict]


sol = Solution()
ans = sol.groupStrings(["az", "ba", "abc", "bcd", "acef", "xyz", "a", "z"])
print(ans)