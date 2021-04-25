/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-02-04 23:04:05
 * @LastEditTime: 2021-02-04 23:16:00
 * @FilePath: \Leetcode\643.Maximum Average Subarray I.cpp
 */
/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
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
TIME:    116ms    BEAT: 99.73%    O(n) = 
MEMORY: 69.7MB    BEAT: 99.73%    O(n) = 
LAST EDIT TIME: 2021年2月4日23:15:59
Description: 
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double ans;
        for (int i = 0; i < k; i ++) {
            ans += nums[i];
        }
        left ++;
        double tmp = ans;
        for (int i = left; i < nums.size() - k + 1; i ++) {
            tmp = tmp - nums[left - 1] + nums[left + k - 1];
            ans = max(tmp, ans);
            left ++;
        }
        return ans / k;
    }
};

// @lc code=end

