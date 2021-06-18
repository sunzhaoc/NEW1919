/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 09:58:04
 * @LastEditTime: 2021-03-25 10:51:10
 * @FilePath: \Leetcode\47.Permutations II.cpp
 */
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
TIME:     8ms    BEAT: 75.40%    O(n) = 
MEMORY: 8.6MB    BEAT: 74.98%    O(n) = 
LAST EDIT TIME: 2021年3月25日10:49:51
Description: 二刷。前一次是python。不过cpp没有对类似python对列表的直接处理。所以麻烦一点。
没写出来。
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTrack(nums, used);
    }

    void backTrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backTrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};

// @lc code=end

