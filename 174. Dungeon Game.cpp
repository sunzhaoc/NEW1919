/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 09:45:58
 * @LastEditTime: 2021-03-09 10:19:54
 * @FilePath: \Leetcode\174.Dungeon Game.cpp
 */
/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
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
TIME:    12ms    BEAT: 54.74%    O(n) = 
MEMORY: 8.8MB    BEAT: 22.57%    O(n) = 
LAST EDIT TIME: 2021年3月9日10:17:47
Description: 官解。写法上更简洁一点。
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));
        dp[row][col - 1] = dp[row - 1][col] = 1;
        for (int i = row - 1; i >= 0; i --) {
            for (int j = col - 1; j >= 0; j --) {
                int minn = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 84.68%    O(n) = 
MEMORY: 8.8MB    BEAT: 33.92%    O(n) = 
USED TIME: 24:40
LAST EDIT TIME: 2021年3月9日10:11:48
Description: Easy DP
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[row - 1][col - 1] = dungeon[row - 1][col - 1] >= 0 ? 1 : abs(dungeon[row - 1][col - 1]) + 1;

        for (int i = row - 2; i >= 0; i --) {
            dp[i][col - 1] = dp[i + 1][col - 1] - dungeon[i][col - 1] > 0 ? dp[i + 1][col - 1] - dungeon[i][col - 1] : 1;
        }
        for (int i = col - 2; i >= 0; i --) {
            dp[row - 1][i] = dp[row - 1][i + 1] - dungeon[row - 1][i] > 0 ? dp[row - 1][i + 1] - dungeon[row - 1][i] : 1;
        }

        for (int i = row - 2; i >= 0; i --) {
            for (int j = col - 2; j >= 0; j --) {
                int a = dp[i][j + 1] - dungeon[i][j] > 0 ? dp[i][j + 1] - dungeon[i][j] : 1;
                int b = dp[i + 1][j] - dungeon[i][j] > 0 ? dp[i + 1][j] - dungeon[i][j] : 1;
                dp[i][j] = min(a, b);
            }
        }
        return dp[0][0];
    }
};



int main() {
    Solution sol;
    vector<vector<int>> dungeon = {{-2,-3,3}, {-5,-10,1}, {10,30,-5}};
    int ans = sol.calculateMinimumHP(dungeon);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

