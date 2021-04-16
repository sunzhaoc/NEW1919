/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-04 08:34:47
 * @LastEditTime: 2021-03-04 09:51:12
 * @FilePath: \Leetcode\300.Longest Increasing Subsequence.cpp
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
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
TIME:      4ms    BEAT: 99.76%    O(n) = nlogn
MEMORY: 10.3MB    BEAT: 53.59%    O(n) = n
LAST EDIT TIME: 2021年3月4日9:43:34
Description: 二分，有点BT啊。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> tail(nums.size(), 0);
        int ans = 0;
        for (int num: nums) {
            int left = 0, right = ans;
            while (left < right) {
                int mid = (right - left) / 2 + left;
                if (tail[mid] < num) left = mid + 1;
                else right = mid;
            }
            tail[left] = num;
            if (right == ans) ans += 1;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:    328ms    BEAT: 58.03%    O(n) = n^2
MEMORY: 10.2MB    BEAT: 82.96%    O(n) = n
USED TIME: 15:04
LAST EDIT TIME: 2021年3月4日9:6:13
Description: DP
*/

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.size() == 1) return 1;
//         vector<int> dp(nums.size(), 1);
//         for (int i = 0; i < nums.size(); i ++) {
//             for (int j = 0; j < i; j ++) {
//                 if (nums[j] < nums[i]) dp[i] = max(dp[j] + 1, dp[i]);
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {4,10,4,3,8,9};
    int ans = sol.lengthOfLIS(nums);
    system("pause");
    return 0;
}

// @lc code=end

