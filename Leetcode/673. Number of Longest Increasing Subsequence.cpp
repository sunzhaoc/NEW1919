/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-04 15:42:51
 * @LastEditTime: 2021-03-04 19:44:56
 * @FilePath: \Leetcode\673.Number of Longest Increasing Subsequence.cpp
 */
/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
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
using namespace std;


/*
RESULT: Accept
TIME:    156ms    BEAT: 76.51%    O(n) = n^2
MEMORY: 12.6MB    BEAT: 63.82%    O(n) = n
LAST EDIT TIME: 2021年3月4日16:53:54
Description: 太难了。不会。。。看了N久。
https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-dong-tu-fu-zhu-li-jie-ru-you-bang/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> dp_num(nums.size(), 1);

        for (int i = 0; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[j] < nums[i]) {
                    // 第一次找到
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        dp_num[i] = dp_num[j];
                    }

                    // 再一次找到
                    else if (dp[j] + 1 == dp[i]){
                        dp_num[i] += dp_num[j];
                    }
                };
            }
        }
        int max = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for (int i = 0; i < dp.size(); i ++) {
            if (dp[i] == max) ans += dp_num[i];
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // vector<int> nums = {2,2,2,2,2};
    vector<int> nums = {1,3,5,4,7};
    int ans = sol.findNumberOfLIS(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

