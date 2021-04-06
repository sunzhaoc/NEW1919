class Solution:
    def magicTower(self, nums: List[int]) -> int:
        n = len(nums)
        cur_sum = 0
        res = 0
        minSum = 0
        mH = []
        i = 0
        for i in range(n):
            cur_sum += nums[i]
            if nums[i] < 0:
                heapq.heappush(mH, nums[i])
            if cur_sum < 0:
                cur_min = heapq.heappop(mH)
                minSum -= cur_min;
                cur_sum -= cur_min
                res += 1
        if cur_sum < minSum:
            return -1
        return res
