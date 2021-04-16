/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-20 20:28:19
 * @LastEditTime: 2021-01-20 21:01:57
 * @FilePath: \Leetcode\213.House Robber II.cpp
 */
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 7.7MB    BEAT:  95.84%    O(n) = n? 答案写的是1？
USED TIME: 27:58
LAST EDIT TIME: 2021年1月20日20:58:36
Description: DP。分两种情况。一种是不偷第一间房子，另一种是不偷最后一间房子。
Tips：如果将情况分为偷第一和最后一间，则不合适。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        int ans;
        
        // 1. Do not Steal First House
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < nums.size() - 1; i ++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        ans = dp[dp.size() - 1];

        // 2. Do not Steal the First House
        // == Steal the last one
        dp.clear();
        dp.resize(nums.size(), 0);
        dp[dp.size() - 1] = 0;
        dp[dp.size() - 2] = nums[nums.size() - 2];
        for (int i = nums.size() - 3; i >= 0; i --) {
            dp[i] = max(dp[i + 2] + nums[i], dp[i + 1]);
        } 
        
        return max(ans, dp[0]);
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {2,3,2};
    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {1,2,1,1};
    int ans = sol.rob(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

