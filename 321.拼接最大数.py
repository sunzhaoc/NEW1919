'''
Description: k
Version: 1.0
Author: Vicro
Date: 2020-12-02 13:45:44
LastEditTime: 2020-12-02 16:26:47
FilePath: \Leetcode\321.拼接最大数.py
'''
#
# @lc app=leetcode.cn id=321 lang=python3
#
# [321] 拼接最大数
#

# @lc code=start
class Solution:
    def maxNumber(self, nums1, nums2, k):

        def choose_max(nums, k):
            list = []
            drop = len(nums) - k
            for num in nums:
                while drop and list and list[-1] < num:
                    list.pop()
                    drop -= 1
                list.append(num)
            return list[:k]
        
        def merge(A, B):
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger[0])
                bigger.pop(0)
            return ans

        ans = []
        for i in range(k + 1):
            if i <= len(nums1) and k - i <= len(nums2):
                ans = max(merge(choose_max(nums1, i), choose_max(nums2, k - i)), ans)
        return ans
                




"""Time Out, Code is right"""
# class Solution:
    # def maxNumber(self, nums1, nums2, k):
        
        # def choose_max(nums, k, list, res):
        #     if len(list) == temp:
        #         res.append(list)
        #         return res
        #     for j in range(len(nums) - k + 1):
        #         # print(nums[len(nums) - k])
        #         res = choose_max(nums[j + 1:], k - 1, list + [nums[j]], res)
        #     return res


        # def find_max(res):
        #     if len(res) == 1 and res[0] == []: return []
        #     for j in range(len(res[0])):
        #         c = len(res[0])-1-j
        #         res.sort(key=lambda x: (-x[c]))
        #     return res[0]

        # def merge(A, B):
        #     ans = []
        #     for j in range(len(A) + len(B)):
        #         big = A if A > B else B
        #         ans.append(big[0])
        #         big.pop(0)
        #     return ans
        
        # result = []   
        # for i in range(k + 1):
        #     print(i)
        #     if i <= len(nums1) and k - i <= len(nums2):
        #         temp = i
        #         res1 = choose_max(nums1, i, [], [])
        #         res1 = find_max(res1)

        #         temp = k - i
        #         res2 = choose_max(nums2, k - i, [], [])
        #         res2 = find_max(res2)

        #         result.append(merge(res1, res2))
            
        # result = find_max(result)
        # return result


import time
start_time = time.time()
sol = Solution()
result = sol.maxNumber([3, 4, 6, 5], [9, 1, 2, 5, 8, 3], 5)
# result = sol.maxNumber([8,0,4,4,1,7,3,6,5,9,3,6,6,0,2,5,1,7,7,7,8,7,1,4,4,5,4,8,7,6,2,2,9,4,7,5,6,2,2,8,4,6,0,4,7,8,9,1,7,0], [6,9,8,1,1,5,7,3,1,3,3,4,9,2,8,0,6,9,3,3,7,8,3,4,2,4,7,4,5,7,7,2,5,6,3,6,7,0,3,5,3,2,8,1,6,6,1,0,8,4], 50)
print(result)
print(time.time() - start_time)
                
        
# @lc code=end

