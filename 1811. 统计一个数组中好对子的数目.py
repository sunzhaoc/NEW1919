'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-03 23:21:55
LastEditTime: 2021-04-04 00:04:22
FilePath: \Leetcode\demo03.py
'''
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-03 23:21:55
 * @LastEditTime: 2021-04-03 23:21:56
 * @FilePath: \Leetcode\demno3.cpp
 */


class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        n = len(nums)
        dic = defaultdict(int)
        
        for num in nums:
            cha = num - int(str(num)[::-1])
            dic[cha] += 1
        
        res = 0
        for id, num in dic.items():
            res += (num * (num - 1) // 2)
            res %= 1000000007
            
        return res