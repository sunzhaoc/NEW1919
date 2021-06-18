/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-01 10:20:36
 * @LastEditTime: 2021-03-01 10:31:06
 * @FilePath: \Leetcode\283.Move Zeroes.cpp
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
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
TIME:     4ms    BEAT: 95.26%    O(n) = n
MEMORY: 8.8MB    BEAT: 55.97%    O(n) = 1
USED TIME: 08:55
LAST EDIT TIME: 2021年3月1日10:30:16
Description: 
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0, tmp;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != 0) {
                tmp = nums[i];
                nums[i] = 0;
                nums[index] = tmp;
                index ++;
            }
        }
    }
};

// @lc code=end

