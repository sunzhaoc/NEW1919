/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-18 14:59:34
 * @LastEditTime: 2021-01-18 20:10:00
 * @FilePath: \Leetcode\611.Valid Triangle Number.cpp
 */
/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
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
TIME:     24ms    BEAT: 97.37%    O(n) = n^2
MEMORY: 11.1MB    BEAT: 99.33%    O(n) = logn
LAST EDIT TIME: 2021年1月18日18:56:21
Description: 双指针。与下面的方法一样。只是可读性高一点。下面啥fuck玩意？
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        int N = nums.size();
        for (int i = N - 1; i >= 2; i --) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += r - l;
                    r --;
                } else {
                    l ++;
                }
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     28ms    BEAT: 88.82%    O(n) = n^2logn
MEMORY: 11.2MB    BEAT: 97.99%    O(n) = logn
LAST EDIT TIME: 2021年1月18日18:56:21
Description: 双指针。重点是要枚举最大边，而不是最小边。这个双指针就很迷？这啥玩意？
*/

// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         if (nums.size() < 3) return 0;
//         sort(nums.begin(), nums.end(), greater<int>());
//         int res = 0;
//         int N = nums.size();
//         for (int i = 0; i < N - 2; ++i) {
//             int l = i + 1;
//             int r = N - 1;
//             while (l < r) {
//                 if (nums[l] + nums[r] <= nums[i]) {
//                     -- r;
//                 } else {
//                     res += r - l;
//                     ++ l;
//                 }
//             }
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:    100ms    BEAT: 23.25%    O(n) = n^2 * logn
MEMORY: 11.2MB    BEAT: 98.21%    O(n) = logn 排序所用的时间
USED TIME: 31:19
LAST EDIT TIME: 2021年1月18日16:4:11
Description: 二分法。同样的二分，时间差很多。
*/

// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         if (nums.size() < 3) return 0;
//         sort(nums.begin(), nums.end());
//         int l, r, mid, target;
//         int count = 0;
//         for (int i = 0; i < nums.size() - 2; i ++) {
//             if (nums[i] == 0) continue;
//             for (int j = i + 1; j < nums.size() - 1; j ++) {
//                 if (nums[j] == 0) continue;
//                 l = j + 1;
//                 r = nums.size() - 1;
//                 target = nums[i] + nums[j];
//                 while (l < r) {
//                     mid = (r - l) / 2 + l;
//                     if (nums[mid] >= target) r = mid;
//                     else if (nums[mid] < target) l = mid + 1;
//                 }
//                 if (nums[l] >= target) count += (l - j - 1);
//                 else count += (l - j);
//             }
//         }
//         return count;
//     }
// };


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = n^3
MEMORY: MB    BEAT: %    O(n) = 1
LAST EDIT TIME: 
Description: 暴力法。
*/

// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         vector<int> tmp;
//         vector<int> tmp2;
//         int count = 0;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i ++) {
//             if (nums[i] == 0) continue;
//             tmp.push_back(nums[i]);
//             for (int j = i + 1; j < nums.size(); j ++) {
//                 if (nums[j] == 0) continue;
//                 tmp.push_back(nums[j]);
//                 for (int k = j + 1; k < nums.size(); k ++) {
//                     if (nums[k] == 0) continue;
//                     tmp.push_back(nums[k]);
//                     tmp2 = tmp;
//                     sort(tmp2.begin(), tmp2.end());
//                     if (tmp2[0] + tmp2[1] > tmp[2]) {
//                         count ++;
//                         tmp.pop_back();
//                     }
//                     else {
//                         tmp.pop_back();
//                         break;
//                     }
//                 }
//                 tmp.pop_back();
//             }
//             tmp.pop_back();
//         }
//         return count;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {2,2,3,4};
    // vector<int> nums = {0,1,1,1};
    // vector<int> nums = {1,2,3,4,5,6};
    vector<int> nums = {24,3,82,22,35,84,19};
    int ans = sol.triangleNumber(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

