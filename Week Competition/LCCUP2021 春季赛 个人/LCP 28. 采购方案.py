'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-05 14:49:44
LastEditTime: 2021-04-05 16:59:02
FilePath: \Leetcode\weekcom\t1.py
'''



# sol = Solution()
# ans = sol.
# print(ans)

class Solution:
    def purchasePlans(self, nums: List[int], target: int) -> int:
        N = 1000000007
        n = len(nums)
        nums.sort()
        cnt = 0
        
        for i in range(n):
            diff = target - nums[i]
            
            pos = bisect.bisect_left(nums, diff + 1)
            pos -= 1
            
            if pos < i: continue
            
            cur = pos - i
            cnt += cur
            cnt %= N
            
        return cnt