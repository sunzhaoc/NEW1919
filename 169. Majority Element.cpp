/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-01 09:08:36
 * @LastEditTime: 2021-03-01 09:30:27
 * @FilePath: \Leetcode\169.Majority Element.cpp
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:   20ms    BEAT: 73.63%    O(n) = n
MEMORY: 19MB    BEAT: 56.87%    O(n) = 1
LAST EDIT TIME: 2021年3月1日9:14:33
Description: 摩尔投票法。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val, cnt = 0;
        for (auto x: nums) {
            if (!cnt) {
                val = x;
                cnt ++;
            }
            else {
                if (x == val) cnt ++;
                else cnt --;
            }
        }

        return val;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 57.70%    O(n) = n
MEMORY: 19.2MB    BEAT: 15.74%    O(n) = n
USED TIME: 04:19
LAST EDIT TIME: 2021年3月1日9:14:33
Description: 
*/

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> map;
//         for (int i = 0; i < nums.size(); i ++) {
//             map[nums[i]] ++;
//             if (map[nums[i]] > nums.size() / 2) return nums[i];
//         }

//         return -1;
//     }
// };

// @lc code=end

