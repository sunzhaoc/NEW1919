/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 14:58:20
 * @LastEditTime: 2021-03-31 08:54:35
 * @FilePath: \Leetcode\90.Subsets II.cpp
 */
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 66.56%    O(n) = 
MEMORY: 7.5MB    BEAT: 53.89%    O(n) = 
USED TIME: 12:28
LAST EDIT TIME: 2021年3月31日8:53:54
Description: 二刷。花了点时间。
*/

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        backTrack(nums, tmp, 0);
        return res;
    }
    
    void backTrack(vector<int>& nums, vector<int>& used, int index) {
        res.push_back(used);
        if (index == nums.size()) return;
        for (int i = index; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1] && i - 1 >= index) continue;
            used.push_back(nums[i]);
            backTrack(nums, used, i + 1);
            used.pop_back();
        }
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 34.65%    O(n) = 
MEMORY: 7.6MB    BEAT: 48.20%    O(n) = 
USED TIME: 19:59
Description: 递归 + 剪枝。
*/

class Solution {
public:
    vector<vector<int>> ans;

    void backTrack(vector<int>& nums, int index, vector<int>& sub_nums){
        ans.push_back(sub_nums);
        if (index == nums.size()) return;

        for (int i = index; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1] && (i - 1) >= index) continue;
            sub_nums.push_back(nums[i]);
            backTrack(nums, i + 1, sub_nums);
            sub_nums.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub_nums;
        sort(nums.begin(), nums.end());
        backTrack(nums, 0, sub_nums);    
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1};
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    system("pause");
    return 0;
}

// @lc code=end

