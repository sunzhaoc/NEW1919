'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2020-12-24 09:16:30
LastEditTime: 2020-12-24 10:42:00
FilePath: \Leetcode\135.分发糖果.py
'''
#
# @lc app=leetcode.cn id=135 lang=python3
#
# [135] 分发糖果
#

# @lc code=start


"""
RESULT: Accept
TIME:     88ms    BEAT: 44.52%    O(n) = n
MEMORY: 16.5MB    BEAT: 18.08%    O(n) = n
Description: 贪心。
"""

class Solution:
    def candy(self, ratings):
        if len(ratings) == 1:   return 1
        
        candy1 = [1] * len(ratings)
        candy2 = [1] * len(ratings)
        
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]: candy1[i] = candy1[i - 1] + 1
            if ratings[len(ratings) - 1 - i] > ratings[len(ratings) - i]:   candy2[len(ratings) - 1 - i] = candy2[len(ratings) - i] + 1
        
        ans = 0
        for i in range(len(ratings)):
            ans += max(candy1[i], candy2[i])     
        return ans


sol = Solution()
# ans = sol.candy([1, 0, 2])
# ans = sol.candy([1, 2, 2])
# ans = sol.candy([1, 3, 2, 2, 1])
ans = sol.candy([1,2,87,87,87,2,1])
print(ans)

# @lc code=end

