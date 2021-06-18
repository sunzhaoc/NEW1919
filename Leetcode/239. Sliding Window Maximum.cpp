/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-17 21:09:55
 * @LastEditTime: 2021-03-18 16:22:20
 * @FilePath: \Leetcode\239.滑动窗口最大值.cpp
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     296ms    BEAT: 79.37%    O(n) = 
MEMORY: 128.9MB    BEAT: 10.20%    O(n) = 
LAST EDIT TIME: 2021年3月18日16:22:12
Description: 单调双端队列。
是下面单调栈折改进版。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;

        for (int i = 0; i < k; i ++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }

        vector<int> res = {nums[q.front()]};

        for (int i = k; i < nums.size(); i ++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);

            while (q.front() <= i - k) q.pop_front();
            res.emplace_back(nums[q.front()]);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     396ms    BEAT: 69.01%    O(n) = nlogn
MEMORY: 142.2MB    BEAT:  7.38%    O(n) = n
LAST EDIT TIME: 2021年3月18日16:6:16
Description: 单调栈真香。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i ++) {
            q.push({nums[i], i});
        }
        vector<int> res = {q.top().first};
        for (int i = k; i < nums.size(); i ++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) q.pop();
            res.emplace_back(q.top().first);
        }
        return res;
    }
};


/*
RESULT: Time Out
LAST EDIT TIME: 2021年3月18日15:55:40
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k > nums.size()) return {};
        int time = nums.size() - k;
        vector<int> res;
        for (int i = 0; i <= time; i ++) {
            res.emplace_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        }
        return res;
    }
};


// @lc code=end

