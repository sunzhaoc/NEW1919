'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-03-03 08:36:10
LastEditTime: 2021-03-03 09:04:36
FilePath: \Leetcode\338.比特位计数.py
'''
#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#

# @lc code=start

"""
RESULT: Accept
TIME:     84ms    BEAT: 84.20%    O(n) = n
MEMORY: 21.4MB    BEAT: 24.47%    O(n) = n
USED TIME: 01:05
LAST EDIT TIME: 2021年3月3日9:3:38
Description: 布赖恩·克尼根算法 + DP
https://leetcode-cn.com/problems/counting-bits/solution/c-bu-lai-en-ke-ni-gen-suan-fa-dong-tai-g-17ym/
"""

class Solution:
    def countBits(self, num: int) -> List[int]:
        ans = [0] * (num + 1)
        for i in range(1, num + 1):
            ans[i] = ans[i & (i - 1)] + 1
        return ans


"""
RESULT: Accept
TIME:     80ms    BEAT: 92.69%    O(n) = n
MEMORY: 21.2MB    BEAT: 71.99%    O(n) = n
USED TIME: 05:55
LAST EDIT TIME: 2021年3月3日8:43:56
Description: 
"""

class Solution:
    def countBits(self, num):
        ans = [-1] * (num + 1)
        ans[0] = 0
        for i in range(1, num + 1):
            if i % 2 == 1:
                ans[i] = ans[i - 1] + 1
            else:
                ans[i] = ans[i // 2]
        return ans


sol = Solution()
ans = sol.countBits(4)
print(ans)

# @lc code=end

