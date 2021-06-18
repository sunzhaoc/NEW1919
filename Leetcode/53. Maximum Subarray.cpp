/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 13:58:32
 * @LastEditTime: 2021-01-18 14:07:23
 * @FilePath: \Leetcode\53.Maximum Subarray.cpp
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
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
TIME:      8ms    BEAT: 97.71%    O(n) = n
MEMORY: 12.9MB    BEAT: 95.78%    O(n) = n
USED TIME: 03:04
LAST EDIT TIME: 2021年1月18日14:7:22
Description: DP
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = sol.maxSubArray(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

