/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 13:26:57
 * @LastEditTime: 2021-01-18 13:56:29
 * @FilePath: \Leetcode\152.Maximum Product Subarray.cpp
 */
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
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
TIME:      8ms    BEAT: 85.98%    O(n) = n
MEMORY: 11.4MB    BEAT: 99.45%    O(n) = 1
LAST EDIT TIME: 2021年1月18日13:56:14
Description: DP空间优化版本。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_num = nums[0], min_num = nums[0];
        int per_max, per_min;
        int ans = max_num;
        for (int i = 1; i < nums.size(); i ++){
            per_max = max_num;
            per_min = min_num;
            max_num = max(per_max * nums[i], max(nums[i], per_min * nums[i]));
            min_num = min(per_min * nums[i], min(nums[i], per_max * nums[i]));
            ans = max(ans, max_num);
        }

        return ans;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 85.98%    O(n) = n
MEMORY: 11.7MB    BEAT: 92.97%    O(n) = n
USED TIME: 18:14
LAST EDIT TIME: 2021年1月18日13:48:18
Description: DP。
*/

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         vector<int> max_num(nums.size()), min_num(nums.size());
//         max_num[0] = nums[0];
//         min_num[0] = nums[0];
//         for (int i = 1; i < nums.size(); i ++){
//             max_num[i] = max(max_num[i - 1] * nums[i], max(nums[i], min_num[i - 1] * nums[i]));
//             min_num[i] = min(min_num[i - 1] * nums[i], min(nums[i], max_num[i - 1] * nums[i]));
//         }

//         return *max_element(max_num.begin(), max_num.end());
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    // vector<int> nums = {-2,0,-1};
    int ans = sol.maxProduct(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

