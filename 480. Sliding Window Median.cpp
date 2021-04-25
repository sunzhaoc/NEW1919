/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-02-03 18:12:35
 * @LastEditTime: 2021-02-03 19:09:06
 * @FilePath: \Leetcode\480.Sliding Window Median.cpp
 */
/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
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
TIME:    276ms    BEAT: 16.76%    O(n) = 
MEMORY: 15.5MB    BEAT: 50.57%    O(n) = 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> st;
        for (int i = 0; i < nums.size(); i ++) {
            if (st.size() >= k) st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            if (i >= k - 1) {
                auto mid = st.begin();
                std::advance(mid, k / 2);
                res.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
            }
        }
        return res;
    }
};
// @lc code=end

