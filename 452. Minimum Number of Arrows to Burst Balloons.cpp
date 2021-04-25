/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 08:50:57
 * @LastEditTime: 2021-03-09 08:58:34
 * @FilePath: \Leetcode\452.Minimum Number of Arrows to Burst Balloons.cpp
 */
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
TIME:   164ms    BEAT: 81.88%    O(n) = nlogn
MEMORY:  38MB    BEAT: 42.08%    O(n) = logn
USED TIME: 04:31
LAST EDIT TIME: 2021年3月9日8:56:532
Description: 
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (auto ball: points) {
            if (ball[0] > pos) {
                pos = ball[1];
                ans ++;
            }
        }
        return ans;
    }
};

// @lc code=end

