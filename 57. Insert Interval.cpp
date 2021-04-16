/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 17:01:35
 * @LastEditTime: 2021-03-08 18:44:05
 * @FilePath: \Leetcode\57.Insert Interval.cpp
 */
/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
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
TIME:     32ms    BEAT: 37.98%    O(n) = nlogn
MEMORY: 16.6MB    BEAT: 85.92%    O(n) = n
USED TIME: 21:44
LAST EDIT TIME: 2021年3月8日17:24:6
Description: 
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() + newInterval.size() == 0) return {};
        if (intervals.size() == 0) return {newInterval};
        if (newInterval.size() == 0) return {intervals};

        vector<vector<int>> ans;
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
        });

        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] > intervals[i - 1][1]) ans.emplace_back(intervals[i - 1]);
            else {
                intervals[i][0] = intervals[i - 1][0];
            }
        }

        ans.emplace_back(intervals[intervals.size()-1]);
        return ans;
    }
};
// @lc code=end

