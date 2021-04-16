/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 15:58:35
 * @LastEditTime: 2021-03-08 16:16:58
 * @FilePath: \Leetcode\56.Merge Intervals.cpp
 */
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
TIME:     20ms    BEAT: 92.02%    O(n) = nlogn
MEMORY: 13.7MB    BEAT: 95.69%    O(n) = logn
USED TIME: 13:48
LAST EDIT TIME: 2021年3月8日16:14:17
Description: 
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
        });
        int id = 1;
        int L = intervals[0][0], R = intervals[0][1];

        vector<vector<int>> ans;
        while (id < intervals.size()) {
            if (intervals[id][0] >= L && intervals[id][0] <= R) {
                R = max(R, intervals[id][1]);
                id ++;
            }
            else if (intervals[id][0] > R) {
                ans.push_back({L, R});
                L = intervals[id][0], R = intervals[id][1];
                id ++;
            }
        }
        if (L <= R) ans.push_back({L, R});
        return ans;
    }
};

// @lc code=end

