'''
Description: 
Version: 1.0
Author: Vicro
Date: 2020-11-30 22:03:12
LastEditTime: 2020-12-01 13:47:32
FilePath: \Leetcode\77.组合.py
'''
#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#

# @lc code=start
class Solution:
    # def combine(self, n: int, k: int) -> List[List[int]]:
    def combine(self, n, k):

        res = []
        
        def backTrack(start, list):
            if len(list) == k:
                res.append(list)
                return

            for i in range(start, n - (k - len(list)) + 1 + 1):
                # n - 最后一个值
                # (k -len(list)) - 跟据已选的数字，计算还要选的长度
                # + 1 多减了一个要加回来
                # + 1 for的性质，要加1
                backTrack(i + 1, list + [i])

        backTrack(1, [])
        return res


        """Method 02"""
        # res = []
        
        # def backTrack(first, list):
        #     if len(list) == k:
        #         res.append(list)
        #         return
        #     for i in range(first, n + 1 + len(list) - k + 1):
        #         backTrack(i + 1, list + [i])
        # backTrack(1, [], )
        # return res


        """Method 01"""
        # res = []
        # nums = [i + 1 for i in range(n)]
        
        # def backTrack(level, list, tochoose_list):
        #     if level == k:
        #         return res.append(list)
        #     if level > k:
        #         return
            
        #     for i in range(len(tochoose_list)):
        #         backTrack(level + 1, list + [tochoose_list[i]], tochoose_list[i + 1:])
        # backTrack(0, [], nums)
        # return res

import time
start = time.time()
sol = Solution()
A = sol.combine(4, 3)
print(A)
print((time.time() - start)*1000, "ms")

# @lc code=end

