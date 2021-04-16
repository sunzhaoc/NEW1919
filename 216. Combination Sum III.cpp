/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 15:52:29
 * @LastEditTime: 2021-04-04 16:00:38
 * @FilePath: \Leetcode\216.Combination Sum III.cpp
 */
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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
TIME:     4ms    BEAT: 36.05%    O(n) = 
MEMORY: 6.2MB    BEAT: 79.52%    O(n) = 
USED TIME: 06:58
LAST EDIT TIME: 2021年4月4日15:59:58
Description: Easy。回溯。
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp = {};
        dfs(k, n, tmp, 0);
        return ans;
    }

    void dfs(int k, int n, vector<int>& nums, int minNum) {
        if (k == 0 && n == 0) {
            ans.push_back(nums);
            return;
        }
        if (n < 0) return;
        for (int i = minNum + 1; i <= 9; i ++) {
            nums.push_back(i);
            dfs(k - 1, n - nums.back(), nums, i);
            nums.pop_back();
        }
        return;
    }
};
// @lc code=end

