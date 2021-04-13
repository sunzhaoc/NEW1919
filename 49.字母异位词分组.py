'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-14 10:38:06
LastEditTime: 2021-03-03 15:51:18
FilePath: \Leetcode\49.字母异位词分组.py
'''
#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start

"""
RESULT: Accept
TIME:     56ms    BEAT: 82.75%    O(n) = 
MEMORY: 17.6MB    BEAT: 19.59%    O(n) = 
Description: 官解，与下面的方法相同，只是更简洁一点。
"""

# import collections
# class Solution:
#     def groupAnagrams(self, strs):
#         mp = collections.defaultdict(list)

#         for st in strs:
#             key = "".join(sorted(st))
#             mp[key].append(st)
        
#         return list(mp.values())


"""
RESULT: Accept
TIME:     56ms    BEAT: 82.75%    O(n) = 
MEMORY: 17.3MB    BEAT: 20.63%    O(n) = 
Description: 
"""

class Solution:
    def groupAnagrams(self, strs):
        if strs == []: return []

        dic = {}
        for i in strs:
            temp = "".join(sorted(i))
            if temp in dic.keys():
                dic[temp].append(i)
            else:
                dic[temp] = [i]
        
        return [dic[i] for i in dic]


sol = Solution()
A = sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
print(A)

# @lc code=end

