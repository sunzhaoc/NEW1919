/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-12 10:09:44
 * @LastEditTime: 2021-07-09 15:51:36
 * @FilePath: \Leetcode\test01.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
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
TIME:   12ms    BEAT: 80.10%    O(n) = n
MEMORY:  9MB    BEAT: 39.21%    O(n) = n
USED TIME: 哈希表。
Description: 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {i, it->second};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};


/*
RESULT: Accept
TIME:   12ms    BEAT: 80.10%    O(n) = n^2
MEMORY:  9MB    BEAT: 87.50%    O(n) = 1
USED TIME: 05:31
Description: 暴力枚举。
*/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         for (int i = 0; i < nums.size(); i ++) {
//             int cha = target - nums[i];
//             for (int j = i + 1; j < nums.size(); j ++) {
//                 if (nums[j] + nums[i] == target) {
//                     res.push_back(i);
//                     res.push_back(j);
//                     return res;
//                 }
//             }
//         }
//         return {};
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    
    vector<int> ans = sol.twoSum(nums, 9);
    for (int &i: ans) cout << i << endl;
    system("pause");
    return 0;
}


// @lc code=end

