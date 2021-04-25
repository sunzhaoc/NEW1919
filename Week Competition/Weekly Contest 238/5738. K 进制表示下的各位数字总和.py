'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-04-25 10:18:02
LastEditTime: 2021-04-25 13:43:37
FilePath: \Leetcode\Week Competition\Weekly Contest 238\5738. K 进制表示下的各位数字总和.py
'''


class Solution:
    def sumBase(self, n: int, k: int) -> int:
        nums = []
        while n:
            a = n % k
            nums.append(a)
            n //= k
        return sum(nums)


# sol = Solution()
# ans = sol.
# print(ans)
