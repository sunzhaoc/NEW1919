'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2020-12-24 13:07:30
LastEditTime: 2020-12-24 14:22:04
FilePath: \Leetcode\剑指 Offer 38. 字符串的排列.py
'''

"""
RESULT: Accept
TIME:    120ms    BEAT: 80.78%    O(n) = 
MEMORY: 19.3MB    BEAT: 21.13%    O(n) = 
Description: 与下面的方法相同。只不过传递的是索引所以更快一些。
"""

class Solution:
    def permutation(self, s):
        s = list(s)
        ans = []

        def dfs(x):
            if x == len(s) - 1:
                ans.append(''.join(s))
                return
            dic = set()
            for i in range(x, len(s)):
                if s[i] in dic:    continue
                dic.add(s[i])

                s[i], s[x] = s[x], s[i]
                dfs(x + 1)
                s[i], s[x] = s[x], s[i]

        dfs(0)
        return ans


"""
RESULT: Accept
TIME:    200ms    BEAT: 36.71%    O(n) = 
MEMORY: 19.5MB    BEAT: 18.97%    O(n) = 
Description: 回溯 + 剪枝。
"""

# class Solution:
#     def permutation(self, s):
#         ans = []

#         def dfs(used, to_use):
#             if len(used) == len(list(s)):
#                 ans.append(used)
#                 return
#             dic = set()
#             for i in range(len(to_use)):
#                 if to_use[i] in dic:    continue
#                 dic.add(to_use[i])
#                 dfs(used + to_use[i], to_use[:i] + to_use[i + 1:])

#         dfs("", list(s))
#         return ans


"""
RESULT: Accept
TIME:    352ms    BEAT: 16.23%    O(n) = 
MEMORY: 28.9MB    BEAT:  5.00%    O(n) = 
Description: 回溯。仅在最后去除重复的元素。
"""

# class Solution:
#     def permutation(self, s):
#         ans = []
#         # s = list(set(s))

#         def dfs(used, to_use):
#             if len(used) == len(list(s)):
#                 ans.append(used)
#                 return
#             for i in range(len(to_use)):
#                 dfs(used + to_use[i], to_use[:i] + to_use[i + 1:])

#         dfs("", list(s))
#         return list(set(ans))


sol = Solution()
ans = sol.permutation("aab")
print(ans)
