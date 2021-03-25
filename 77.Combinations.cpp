/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-25 10:52:00
 * @LastEditTime: 2021-03-25 11:02:36
 * @FilePath: \Leetcode\77.Combinations.cpp
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
TIME:    28ms    BEAT: 55.83%    O(n) = 
MEMORY: 9.8MB    BEAT: 48.02%    O(n) = 
USED TIME: 04:48
LAST EDIT TIME: 2021年3月25日11:2:26
Description: 二刷。前一次是python。
*/

class Solution {
public: 
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        backTrack(1, n, k);
        return res;
    }

    void backTrack(int start, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i ++) {
            path.push_back(i);
            backTrack(i + 1, n, k);
            path.pop_back();
        }
    }
};

// @lc code=end

