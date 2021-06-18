#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
class Solution:
    def findKthLargest(self, nums, k):
        nums = sorted(nums, key=lambda x: -x)
        return nums[k - 1]

sol = Solution()
A = sol.findKthLargest([3,2,3,1,2,4,5,5,6], 4)
print(A)
# @lc code=end

