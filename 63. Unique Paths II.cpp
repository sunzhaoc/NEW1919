/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 13:59:06
 * @LastEditTime: 2021-03-09 14:14:30
 * @FilePath: \Leetcode\63.Unique Paths II.cpp
 */
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
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
TIME:     4ms    BEAT: 81.73%    O(n) = mn
MEMORY: 7.7MB    BEAT: 50.89%    O(n) = m
USED TIME: 12:42
LAST EDIT TIME: 2021年3月9日14:13:30
Description: Easy DP
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] =  obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < m; i ++) {
            dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
        }
        for (int i = 1; i < n; i ++) {
            dp[0][i] = obstacleGrid[0][i] == 0 ? dp[0][i - 1] : 0;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};



int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    vector<vector<int>> obstacleGrid = {{0,1}, {0,0}};
    int ans = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

