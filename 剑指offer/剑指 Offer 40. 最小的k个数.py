'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-24 18:48:56
LastEditTime: 2020-12-24 20:32:38
FilePath: \Leetcode\剑指 Offer 40. 最小的k个数.py
'''


"""
RESULT: Accept
TIME:     60ms    BEAT: 80.44%    O(n) = nlogn
MEMORY: 15.8MB    BEAT: 10.43%    O(n) = logn
Description: 排序法。时间复杂度即为排序的复杂度。
"""

class Solution:
    def getLeastNumbers(self, arr, k):
        ans = []
        arr.sort(key=lambda x: x)
        for i in range(k):
            ans.append(arr[i])
        return ans


sol = Solution()
ans = sol.getLeastNumbers([3, 2, 1], 2)
print(ans)