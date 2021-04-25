/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-04 14:31:27
 * @LastEditTime: 2021-01-04 16:51:51
 * @FilePath: \Leetcode\78.Subsets.cpp
 */
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 62.46%    O(n) = 
MEMORY: 7.4MB    BEAT: 51.64%    O(n) = 
USED TIME: 19:19
Description: 递归 + 剪枝。
*/

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index, vector<int>& sub_list) {
        if (index == nums.size()) {
            ans.push_back(sub_list);
            return;
        }
        else ans.push_back(sub_list);

        for (int i = index; i < nums.size(); i ++) {
            sub_list.push_back(nums[i]);
            dfs(nums, i + 1, sub_list);
            sub_list.pop_back();
        }
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub_list = {};
        dfs(nums, 0, sub_list);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);
    system("pause");
    return 0;
}

// @lc code=end

