/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-02-07 22:04:21
 * @LastEditTime: 2021-02-07 22:28:47
 * @FilePath: \Leetcode\665.Non-decreasing Array.cpp
 */
/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
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
TIME:     36ms    BEAT: 83.92%    O(n) = 
MEMORY: 26.4MB    BEAT: 84.85%    O(n) = 
LAST EDIT TIME: 2021年2月7日22:28:46
Description: 
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                count ++;
                if (count > 1) return false;
            }
        }
        return true;
    }
};

// @lc code=end

