/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 16:18:41
 * @LastEditTime: 2021-01-05 16:41:16
 * @FilePath: \Leetcode\剑指 Offer 42. 连续子数组的最大和.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     48ms    BEAT: 60.26%    O(n) = n
MEMORY: 22.8MB    BEAT: 73.61%    O(n) = 1
Description: 优化了一下。没有用数组存储。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = nums[0], r;
        int res = l;

        for (int i = 1; i < nums.size(); i ++) {
            r = max(nums[i], l + nums[i]);
            res = res < r ? r : res;
            l = r;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 60.20%    O(n) = n
MEMORY: 23.4MB    BEAT: 14.57%    O(n) = n
USED TIME: 16:57
Description: 
*/

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         vector<int> dp(nums.size());
//         dp[0] = nums[0];
//         int res = dp[0];
//         for (int i = 1; i < nums.size(); i ++) {
//             dp[i] = max(nums[i], dp[i - 1] + nums[i]);
//             res = res < dp[i] ? dp[i] : res;
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = sol.maxSubArray(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}

