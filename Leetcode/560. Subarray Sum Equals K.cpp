/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 16:57:09
 * @LastEditTime: 2021-03-18 20:16:51
 * @FilePath: \Leetcode\560.Subarray Sum Equals K.cpp
 */
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
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
TIME:     92ms    BEAT: 73.71%    O(n) = 
MEMORY: 35.1MB    BEAT: 92.27%    O(n) = 
USED TIME: 05:24
LAST EDIT TIME: 2021年3月18日20:16:25
Description: 二刷。
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0;
        int sum = 0;
        for (int num: nums) {
            sum += num;
            if (map.find(sum - k) != map.end()) res += map[sum - k];
            map[sum] ++;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     84ms    BEAT: 98.89%    O(n) = n
MEMORY: 35.2MB    BEAT: 76.23%    O(n) = n
USED TIME: 04:05
LAST EDIT TIME: 2021年1月14日18:57:6
Description: 前缀和 + 哈希表 优化。初始化哈希表要注意一下。
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0, sum = 0; // 哈希表的初始化要注意一下。
        map[0] = 1;

        for (int &x: nums) {
            sum += x;
            if (map.find(sum - k) != map.end()) count += map[sum - k];
            map[sum] ++;
        }

        return count;
    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = n^2
MEMORY: MB    BEAT: %    O(n) = 1
USED TIME: < 20:00
LAST EDIT TIME: 2021年1月14日17:21:11
Description: 用了和官解一样的方法，超时。官解也超时。。。
*/

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int res = 0;

//         for (int i = 0; i < nums.size(); i ++) {
//             int sum = 0;
//             int point = i;

//             while (point < nums.size()) {
//                 sum += nums[point++];
//                 if (sum == k) {
//                     res ++;
//                 }
//             }
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {-1,-1,1};
    // int k = 0;
    // vector<int> nums = {0};
    // int k = 0;
    // vector<int> nums = {1,-1,0};
    // int k = 0;
    vector<int> nums = {0,0};
    int k = 0;
    int ans = sol.subarraySum(nums, k);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

