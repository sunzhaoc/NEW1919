/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-04 18:02:21
 * @LastEditTime: 2021-01-04 18:57:57
 * @FilePath: \Leetcode\491.Increasing Subsequences.cpp
 */
/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <sstream>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:    108ms    BEAT: 44.36%    O(n) = 
MEMORY: 25.3MB    BEAT: 53.08%    O(n) = 
USED TIME: 42:50
Description: 递归。
*/

class Solution {
public:
    vector<vector<int>> res;

    void backTrack(vector<int>& nums, int index, vector<int>& chosen) {

        if (chosen.size() >= 2) {
            res.push_back(chosen);
        }
        if (index == nums.size()) return;
        
        unordered_set<int> uset;
        for (int i = index; i < nums.size(); i ++) {
            if ((!chosen.empty() && nums[i] < chosen.back()) || uset.find(nums[i]) != uset.end()) continue;
            chosen.push_back(nums[i]);
            backTrack(nums, i + 1, chosen);
            uset.insert(nums[i]);
            chosen.pop_back(); 
        }
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> chosen;
        chosen.clear();
        backTrack(nums, 0, chosen);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> ans = sol.findSubsequences(nums);
    system("pause");
    return 0;
}

// @lc code=end

