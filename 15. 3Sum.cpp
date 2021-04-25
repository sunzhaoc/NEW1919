/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-13 14:23:17
 * @LastEditTime: 2021-01-13 16:33:44
 * @FilePath: \Leetcode\15.3Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

/*
本来是参考01题两数之和，打算用哈希，但是去重相当麻烦。可参考下面的。
https://leetcode-cn.com/problems/3sum/solution/15-san-shu-zhi-he-ha-xi-fa-shuang-zhi-zhen-fa-xi-2/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:   132ms    BEAT: 46.20%    O(n) = n^2
MEMORY:  20MB    BEAT: 49.29%    O(n) = logn 空间复杂度主要取决于排序所用的额外空间。
Description: 双指针。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i ++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int k = nums.size() - 1;
            int j = i + 1;

            while (j < k) {
                if (nums[j] + nums[k] > - nums[i]) k --;
                else if (nums[j] + nums[k] < - nums[i]) j ++;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});

                    while (k > j && nums[k] == nums[k - 1]) k --;
                    while (k > j && nums[j] == nums[j + 1]) j ++;

                    j ++;
                    k --;
                }
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    112ms    BEAT: 72.11%    O(n) = n^2 这个的时间复杂度可以看看。
MEMORY: 20.1MB    BEAT: 35.14%    O(n) = logn
USED TIME: 1:16:37
Description: 双指针。
*/

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;
//         int target = 0;

//         for (int i = 0; i < nums.size(); i ++) {
//             if (i != 0 && nums[i] == nums[i - 1]) continue;

//             target = 0 - nums[i];
//             int k = nums.size() - 1;

//             for (int j = i + 1; j < nums.size(); j ++) {
//                 if (j != i + 1 && nums[j] == nums[j - 1]) continue;

//                 while (j < k && nums[j] + nums[k] > target) k --;

//                 if (j == k) {
//                     break;
//                 }
                
//                 if (nums[j] + nums[k] == target) {
//                     res.push_back({nums[i], nums[j], nums[k]});
//                 }
//             }
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<int> nums = {0,0,0};
    vector<int> nums = {0,2,2,3,0,1,2,3,-1,-4,2};
    // vector<int> nums = {-5,1,-3,-1,-4,-2,4,-1,-1};
    vector<vector<int>> ans = sol.threeSum(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i][0] << " "<< ans[i][1] << " " << ans[i][2] << endl;
    }
    system("pause");
    return 0;
}

// @lc code=end

