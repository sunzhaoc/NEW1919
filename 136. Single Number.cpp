/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-02 21:14:42
 * @LastEditTime: 2021-03-04 21:56:43
 * @FilePath: \Leetcode\136.Single Number.cpp
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
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
TIME:     16ms    BEAT: 94.96%    O(n) = n
MEMORY: 16.4MB    BEAT: 95.57%    O(n) = 1
USED TIME: 01:39
LAST EDIT TIME: 2021年3月4日21:56:0
Description: 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            tmp ^= nums[i];
        } 
        return tmp;
    }
};


/*
Accept: 17.81 22.10
异或
*/

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ans = nums[0];
//         for (int i = 1; i < nums.size(); i++){
//             ans = ans ^ nums[i];
//         }
//         return ans;
//     }
// };

// @lc code=end

