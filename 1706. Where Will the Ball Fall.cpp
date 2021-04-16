/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-28 21:56:29
 * @LastEditTime: 2020-12-28 22:26:04
 * @FilePath: \Leetcode\1706.Where Will the Ball Fall.cpp
 */

#include <vector>
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME:     56ms    BEAT: 100.00%    O(n) = mn
MEMORY: 13.3MB    BEAT: 100.00%    O(n) = n
Description: DP
https://leetcode-cn.com/problems/where-will-the-ball-fall/solution/java-shuang-bai-di-gui-by-ethan-jx-yvx6/
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<int> ans;
        // Initialize position
        for (int i = 0; i < col; i ++) {
            ans.push_back(i);
        }

        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                // Ignore the stuck ball
                if (ans[j] == -1) continue;
                // Right Shift
                if (grid[i][ans[j]] == 1 && ans[j] + 1 < col && grid[i][ans[j] + 1] == 1) ans[j] ++;
                // Left Shift
                else if (grid[i][ans[j]] == -1 && ans[j] - 1 >= 0 && grid[i][ans[j] - 1] == -1) ans[j] --;
                // Stucked
                else ans[j] = -1;
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {};
    vector<int> ans = sol.findBall(grid);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}