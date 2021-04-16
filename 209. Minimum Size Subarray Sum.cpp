/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-18 20:37:38
 * @LastEditTime: 2021-01-18 21:57:30
 * @FilePath: \Leetcode\209.Minimum Size Subarray Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
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
TIME:    12ms    BEAT: 90.42%    O(n) = n
MEMORY: 9.7MB    BEAT: 99.87%    O(n) = 1
LAST EDIT TIME: 2021年1月18日21:34:52
Description: 双指针。
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX;
        int l = 0, r = 0, sum = 0;

        while (r < nums.size()) {
            if (sum + nums[r] < s) {
                r ++;
            }
            else {
                if (r - l < ans) ans = r - l + 1; // 这方法最妙的点就是，这一步不用写成 ans = min(ans, r - l + 1)
                sum -= nums[l];
                l ++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


/*
RESULT: Accept
TIME:    4ms    BEAT: 99.87%    O(n) = nlogn
MEMORY: 10MB    BEAT: 94.51%    O(n) = 1
LAST EDIT TIME: 2021年1月18日21:34:52
Description: 与下面方法相同。但下面每次遍历都从0开始，所以复杂度上去了。
*/

// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int sum = 0, len = INT_MAX, j = 0;
//         for (int i = 0; i < nums.size(); i ++) {
//             sum += nums[i];
//             while (sum >= s) {
//                 len = min(len, i - j + 1);
//                 sum -= nums[j ++];
//             }
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };


/*
RESULT: Accept
TIME:   584ms    BEAT: 15.29%    O(n) = n^2?
MEMORY: 9.9MB    BEAT: 95.41%    O(n) = n
LAST EDIT TIME: 2021年1月18日21:23:51
Description: 前缀和。
*/

// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int map[nums.size()];
//         int sum = 0;
//         int ans = 9999999;
//         for (int i = 0; i < nums.size(); i ++) {
//             sum += nums[i];
//             map[i] = sum;
//             if (sum >= s) {
//                 int k = 0;
//                 while (sum - map[k] >= s && k < i) {
//                     k ++;
//                 }
//                 ans = min(i - k + 1, ans);
//             }
//         }
//         if (sum < s) return 0;
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {2,3,8,9,10,3};
    // vector<int> nums = {1,1};
    int ans = sol.minSubArrayLen(7, nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

