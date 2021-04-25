/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 09:02:25
 * @LastEditTime: 2021-03-09 09:22:21
 * @FilePath: \Leetcode\435.无重叠区间.cpp
 */
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
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
TIME:    16ms    BEAT: 93.85%    O(n) = 
MEMORY: 8.9MB    BEAT: 95.23%    O(n) = 
USED TIME: 14:18
LAST EDIT TIME: 2021年3月9日9:19:0
Description: 贪心。求交叉区间的个数，再用总的区间 - 交叉区间。
https://leetcode-cn.com/problems/non-overlapping-intervals/solution/435-wu-zhong-die-qu-jian-tan-xin-jing-di-qze0/
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        int pos = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] >= pos) {
                pos = intervals[i][1];
                ans ++;
            }
        }
        return intervals.size() - ans;
    }
};

// @lc code=end

