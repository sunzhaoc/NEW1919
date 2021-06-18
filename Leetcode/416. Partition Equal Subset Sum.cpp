/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-22 20:56:40
 * @LastEditTime: 2021-03-22 21:10:15
 * @FilePath: \Leetcode\416.Partition Equal Subset Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <numeric>
using namespace std;


/*
RESULT: Accept
TIME:   204ms    BEAT: 67.77%    O(n) = 
MEMORY: 8.8MB    BEAT: 95.82%    O(n) = 
LAST EDIT TIME: 2021年3月22日21:9:47
Description: 不会。这解法有点6
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i ++) {
            for (int j = target; j > nums[i] - 1; j --) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }        
        return dp.back();
    }
};

// @lc code=end

