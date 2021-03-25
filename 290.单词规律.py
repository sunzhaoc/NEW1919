'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-16 13:16:58
LastEditTime: 2020-12-16 14:34:45
FilePath: \Leetcode\290.单词规律.py
'''
#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#

# @lc code=start


"""
RESULT: Accept
TIME:     36ms    BEAT: 79.88%    O(n) = n + m
MEMORY: 14.6MB    BEAT:  5.37%    O(n) = n + m
Description: 官解。利用split()函数快速分割字符串。
"""

class Solution:
    def wordPattern(self, pattern, str):
        word2ch, ch2word = {}, {}
        words = str.split()
        if len(pattern) != len(words):  return False

        for ch, word in zip(pattern, words):
            if (word in word2ch and word2ch[word] != ch) or (ch in ch2word and ch2word[ch] != word):    return False
            word2ch[word] = ch
            ch2word[ch] = word
        return True


"""
RESULT: Accept
TIME:     48ms    BEAT: 14.16%    O(n) = n + m
MEMORY: 14.9MB    BEAT:  5.37%    O(n) = n + m
Description: 简单的【双射哈希表】思想。
"""

# import collections

# class Solution:
#     def wordPattern(self, pattern, str):
#         dic1 = {}
#         dic2 = {}
#         for i in pattern:
#             temp = ""

#             if str == "":   return False
#             for j in str:
#                 if j != " ":
#                     temp += j
#                 else:
#                     break
#             str = str[len(temp) + 1: ]

#             if i not in dic1.keys():
#                 dic1[i] = temp
#             elif dic1[i] != temp:
#                 return False

#             if temp not in dic2.keys():
#                 dic2[temp] = i
#             elif dic2[temp] != i:
#                 return False
#         if str == "":
#             return True       
#         else:   return False


sol = Solution()
# ans = sol.wordPattern("he", "unit")
ans = sol.wordPattern("abba", "dog cat cat fish")
print(ans)
        
# @lc code=end