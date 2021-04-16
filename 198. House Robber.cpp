/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-19 16:05:05
 * @LastEditTime: 2021-01-19 16:19:18
 * @FilePath: \Leetcode\198.House Robber.cpp
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
MEMORY: 7.7MB    BEAT:  94.76%    O(n) = n
LAST EDIT TIME: 2021年1月19日16:18:31
Description: 第一次自己写出来DP，哭了。空间可以简化到1，懒得写了。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i ++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[dp.size() - 1];        
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {2,7,9,3,1};
    int ans = sol.rob(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

