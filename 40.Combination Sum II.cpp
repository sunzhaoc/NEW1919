/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-25 09:42:53
 * @LastEditTime: 2021-03-25 09:57:14
 * @FilePath: \Leetcode\40.Combination Sum II.cpp
 */
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
TIME:     12ms    BEAT: 47.95%    O(n) = 
MEMORY: 10.4MB    BEAT: 70.83%    O(n) = 
USED TIME: 10:28
LAST EDIT TIME: 2021年3月25日9:56:25
Description: 二刷。前一次是python.
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp = {};
        backTrack(tmp, candidates, target, 0);
        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& candidates, int target, int id) {
        if (target == 0) {
            res.push_back(nums);
            return;
        }
        if (target < 0) return;

        for (int i = id; i < candidates.size(); i ++) {
            nums.push_back(candidates[i]);
            backTrack(nums, candidates, target - candidates[i], i + 1);
            nums.pop_back();
        }
        return;
    }
};
// @lc code=end

