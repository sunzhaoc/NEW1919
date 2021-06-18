'''
Description: 
Version: 1.0
Author: 冰凝水
Date: 2020-11-30 17:07:56
LastEditTime: 2020-11-30 21:00:19
FilePath: \Leetcode\39.组合总和.py
'''
#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates, target):
        """参考链接：https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/ """

        
        """Method 03 剪枝"""
        res = []
        n = len(candidates)
        candidates.sort()
        def backTrack(cha, list, use_list):
            if cha == 0:
                res.append(list)
                return
            for i in range(len(use_list)):
                    if cha - use_list[i] < 0:
                        break
                    backTrack(cha - use_list[i], list + [use_list[i]], use_list[i:])
        
        backTrack(target, [], candidates)
        return res
        
        
        """Method 03  排除一些多余的遍历步骤"""
        # res = []
        # n = len(candidates)

        # def backTrack(cha, list, use_list):
        #     if cha < 0:
        #         return
        #     if cha == 0:
        #         res.append(list)
        #         return
        #     for i in range(len(use_list)):
        #             backTrack(cha - use_list[i], list + [use_list[i]], use_list[i:])
        
        # backTrack(target, [], candidates)
        # return res
        
        
        """Method 02 用差值来做"""
        # res = []
        # n = len(candidates)

        # def backTrack(cha, list):
        #     if cha == 0:
        #         temp = sorted(list)
        #         if temp not in res:
        #             res.append(temp)
        #     for i in range(n):
        #         if cha - candidates[i] >= 0:
        #             backTrack(cha - candidates[i], list + [candidates[i]])

        # backTrack(target, [])
        # return res


        """Method 01 正常的回溯法"""
        # res = []
        # n = len(candidates)
        # candidates.sort()

        # def backTrack(level, list):
        #     if sum(list) == target:
        #         temp = sorted(list)
        #         if temp not in res:
        #             res.append(temp)
            
        #     for i in range(n):
        #         if sum(list) < target:
        #             backTrack(i + 1, list + [candidates[i]])
        
        # backTrack(0, [])
        
        # return res    


sol = Solution()
A = sol.combinationSum([2,3,6,7], 7)
print(A)

# @lc code=end

