'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-04 10:07:31
LastEditTime: 2021-04-04 14:50:09
FilePath: \Leetcode\1815.绝对差值和.py
'''

/*
RESULT: Accept
Description: 比赛写的。
能过，但是错误的。
[1, 2, 100] [2, 4, 105] 就过不了。
*/

class Solution:
    def minAbsoluteSumDiff(self, nums1, nums2):
        n = len(nums1)
        res = 0

        diff = []
        for i in range(n):
            diff.append(abs(nums1[i] - nums2[i]))
        
        maxNum2 = -1
        maxId = -1
        for i in range(n):
            if diff[i] > maxNum2:
                maxNum2 = diff[i]
                maxId = i
        
        mindiff = 1000000
        maxNum2 = nums2[maxId]
        for i in range(n):
            if (abs(nums1[i] - maxNum2)) < mindiff:
                mindiff = abs(nums1[i] - maxNum2)
        
        diff[maxId] = mindiff
        
        for i in range(n):
            res += diff[i]
            res %= 1000000007
        
        return res

sol = Solution()
ans = sol.minAbsoluteSumchazhi([1,7,5],[2,3,5])
print(ans)
