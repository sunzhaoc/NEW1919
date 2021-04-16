/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
TIME:      4ms    BEAT: 96.40%    O(n) = 
MEMORY: 10.7MB    BEAT: 68.34%    O(n) = 
USED TIME: 19:05
LAST EDIT TIME: 2021年3月25日9:41:6
Description: 二刷。前一次是python。
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            backTrack(nums, candidates, target - candidates[i], i);
            nums.pop_back();
        }
        
        return;
    }
};



// @lc code=end

