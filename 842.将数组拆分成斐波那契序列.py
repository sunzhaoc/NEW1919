'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-12-08 15:32:57
LastEditTime: 2020-12-08 20:46:13
FilePath: \Leetcode\842.将数组拆分成斐波那契序列.py
'''
#
# @lc app=leetcode.cn id=842 lang=python3
#
# [842] 将数组拆分成斐波那契序列
#

# @lc code=start

"""
RESULT: Accept
TIME:     52ms    BEAT: 78.89%    O(n) = 
MEMORY: 13.6MB    BEAT: 11.93%    O(n) =  
Description: https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/solution/python-3dai-fan-hui-zhi-de-hui-su-jian-z-i9ol/
"""

class Solution:
    def splitIntoFibonacci(self, S):
        m = 2 ** 31 - 1
        res = []
        length = len(S)
        def backtrack(pos):
            # 基线条件
            if pos == length:
                return len(res) > 2
            # 递归条件
            s = 0
            for i in range(pos, length):
                s = s * 10 + int(S[i])
                # 剪枝条件 1：当前项不能大于最大值
                if s > m:
                    break
                # 剪枝条件 2：当前项大于前两项之和，没有继续计算的必要
                if len(res) >= 2 and s > res[-1] + res[-2]:
                    break
                # 剪枝条件 3：当前项以 0 开始，且不是 0 本身
                if S[pos] == '0' and i > pos:
                    break
                if len(res) < 2 or res[-1] + res[-2] == s:
                    # 保存现场
                    res.append(s)
                    # 回溯
                    if backtrack(i + 1):
                        return True
                    # 恢复现场
                    res.pop()
            return False
        return res if backtrack(0) else []


"""
RESULT: Accept
TIME:    112ms    BEAT: 49.34%    O(n) = 
MEMORY: 13.6MB    BEAT: 15.38%    O(n) = 
Description: 从后往前进行遍历。上一个方法的优化版本。
"""

# class Solution:
#     def splitIntoFibonacci(self, S):
#         ans = self.findFirst(S)
#         return ans[::-1]


#     def findFirst(self, S):
#         '''
#         description: 找到符合条件的最后三个数，每后到一个，就判断是否正确。
#         param {*}
#         return {*}
#         '''

#         for i in range(1, (len(S) - 1) // 2 + 1):
#             for j in range(1, min(i + 1, len(S) - i - 1)):
#                 ans = []
#                 A = int(S[-i:]) - int(S[-i-j: -i])
#                 if A == int(S[-i-j-len(str(A)): -i-j]):
#                     # ans.append()
#                     ans.append(int(S[-i:]))
#                     ans.append(int(S[-i-j: -i]))
#                     ans.append(int(S[-i-j-len(str(A)): -i-j]))

#                     if i+j+len(str(A)) == len(S):
#                         return ans
#                     else:
#                         res = self.whetherRight(ans, S)
#                         if res[1] == True:
#                             return res[0]
#                         ans = []
#         return ans


#     def whetherRight(self, A, S):
#         if A[0] > 2**31 - 1 or A[1] > 2**31 - 1 or A[2] > 2**31 - 1:    return [A, False]
#         num = 0  
#         for i in A:
#             num += len(str(i))
#         if num == len(S):
#             return [A, True]
#         S = S[: -num]

#         while (len(S) > 0):
#             V = S[-1:]
#             if A[-2] - A[-1] == int(S[-len(str(A[-2] - A[-1])): ]):
#                 S = S[: -len(str(A[-2] - A[-1]))]
#                 A.append(A[-2] - A[-1])
#             else:
#                 return[A, False]
#         return [A, True]


"""
RESULT: Accept
TIME:    128ms    BEAT: 47.23%    O(n) = 
MEMORY: 13.6MB    BEAT: 11.40%    O(n) = 
Description: 从后往前进行遍历。
"""

# class Solution:
#     def splitIntoFibonacci(self, S):
#         ans = self.findFirst(S)
#         if ans == []:    return []
#         for i in ans:
#             res = self.whetherRight(i, S)
#             if res[1] == True:
#                 return res[0][::-1]
#         return []


#     def findFirst(self, S):
#         '''
#         description: 找到所有符合条件的最后三个数，从而可以算出剩余的数。
#         param {*}
#         return {*}
#         '''
#         ans = []
#         for i in range(1, (len(S) - 1) // 2 + 1):
#             for j in range(1, min(i + 1, len(S) - i - 1)):
#                 A = int(S[-i:]) - int(S[-i-j: -i])
#                 if A == int(S[-i-j-len(str(A)): -i-j]):
#                     ans.append([])
#                     ans[-1].append(int(S[-i:]))
#                     ans[-1].append(int(S[-i-j: -i]))
#                     ans[-1].append(int(S[-i-j-len(str(A)): -i-j]))

#                     if i+j+len(str(A)) == len(S):
#                         return [ans[-1]]
#         return ans


#     def whetherRight(self, A, S):
#         if A[0] > 2**31 - 1 or A[1] > 2**31 - 1 or A[2] > 2**31 - 1:    return [A, False]
#         num = 0  
#         for i in A:
#             num += len(str(i))
#         if num == len(S):
#             return [A, True]
#         S = S[: -num]

#         while (len(S) > 0):
#             V = S[-1:]
#             if A[-2] - A[-1] == int(S[-len(str(A[-2] - A[-1])): ]):
#                 S = S[: -len(str(A[-2] - A[-1]))]
#                 A.append(A[-2] - A[-1])
#             else:
#                 return[A, False]
#         return [A, True]


sol = Solution()
# A = sol.splitIntoFibonacci("112358130")
A = sol.splitIntoFibonacci("123456579")
# A = sol.splitIntoFibonacci("11235813")
# A = sol.splitIntoFibonacci("1101111")
# A = sol.splitIntoFibonacci("0000")
# A = sol.splitIntoFibonacci("0123")
# A = sol.splitIntoFibonacci("539834657215398346785398346991079669377161950407626991734534318677529701785098211336528511")

print(A)
# @lc code=end

