/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-19 16:19:43
 * @LastEditTime: 2021-01-19 16:58:20
 * @FilePath: \Leetcode\238.Product of Array Except Self.cpp
 */
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
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
TIME:     32ms    BEAT: 97.38%    O(n) = n
MEMORY: 23.4MB    BEAT: 98.47%    O(n) = 1
LAST EDIT TIME: 2021年1月19日16:53:58
Description: 太秀了。。。。。。。。。。。。。。。。。。WOC！！！！。。。。。。。
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int left = 1, right = 1;
        
        // 这for循环天秀。跪。
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i ++, j --) {
            ans[i] *= left;
            ans[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 98.32%    O(n) = 3n = n
MEMORY: 24.3MB    BEAT: 34.38%    O(n) = 3n = n
USED TIME: 09:55
LAST EDIT TIME: 2021年1月19日16:33:52
Description: 前缀和 + 后缀和。题目要求不能用除法。
*/

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> frontSum(nums.size()), behindSum(nums.size());
//         vector<int> ans(nums.size());

//         frontSum[0] = nums[0];
//         for (int i = 1; i < nums.size(); i ++) {
//             frontSum[i] = nums[i] * frontSum[i - 1];
//         }

//         behindSum[nums.size() - 1] = nums[nums.size() - 1];
//         for (int i = nums.size() - 2; i >= 0; i --) {
//             behindSum[i] = nums[i] * behindSum[i + 1]; 
//         }

//         for (int i = 0; i < nums.size(); i ++) {
//             if (i == 0) {
//                 ans[i] = behindSum[i + 1];
//             }
//             else if (i == nums.size() - 1) {
//                 ans[i] = frontSum[i - 1];
//             }
//             else {
//                 ans[i] = frontSum[i - 1] * behindSum[i + 1];
//             }
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> ans = sol.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl; 
    }
    system("pause");
    return 0;
}

// @lc code=end

