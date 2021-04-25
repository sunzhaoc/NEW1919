/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 14:50:03
 * @LastEditTime: 2021-03-11 16:04:03
 * @FilePath: \Leetcode\1277.Count Square Submatrices with All Ones.cpp
 */
/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
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
TIME:     76ms    BEAT: 81.49%    O(n) = mn
MEMORY: 25.7MB    BEAT: 50.45%    O(n) = mn
LAST EDIT TIME: 2021年3月11日15:58:45
Description: dp[i][j] 表示以 (i, j) 为右下角的正方形的数目。也表示以 (i, j) 为右下角的正方形的最大边长。
https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-2/
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                ans += dp[i][j];
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> nums = {{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
    int ans = sol.countSquares(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}



// @lc code=end

