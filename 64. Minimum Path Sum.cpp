/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 09:24:34
 * @LastEditTime: 2021-03-09 09:44:47
 * @FilePath: \Leetcode\64.Minimum Path Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
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
TIME:    16ms    BEAT: 50.83%    O(n) = 
MEMORY: 9.9MB    BEAT: 43.86%    O(n) = 
USED TIME: 17:53
LAST EDIT TIME: 2021年3月9日9:43:0
Description: Easy DP
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i ++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < grid[0].size(); j ++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); i ++) {
            for (int j = 1; j < grid[0].size(); j ++) {
                dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};


int main() {
    Solution sol;
    // vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}};
    int ans = sol.minPathSum(grid);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

