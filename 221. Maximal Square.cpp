/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-11 14:09:12
 * @LastEditTime: 2021-03-11 14:49:55
 * @FilePath: \Leetcode\221.Maximal Square.cpp
 */
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
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
TIME:     20ms    BEAT: 98.27%    O(n) = mn
MEMORY: 11.3MB    BEAT: 66.26%    O(n) = mn
LAST EDIT TIME: 2021年3月11日14:46:21
Description: DP。这个状态转移方程建议看一下。
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] == 1;
                    else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 49.26%    O(n) = 
MEMORY: 10.6MB    BEAT: 94.40%    O(n) = 
USED TIME: 13:16
LAST EDIT TIME: 2021年3月11日14:24:59
Description: 暴力法。
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int row = 0; row < matrix.size(); row ++) {
            for (int col = 0; col < matrix[0].size(); col ++) {
                if (matrix[row][col] == '1') {
                    res = max(1, res);
                    int minStep = min(matrix.size() - row, matrix[0].size() - col);
                    // 下面的扩展处理方法可以留意一下。
                    for (int i = 1; i < minStep; i ++) {
                        bool flag = true;
                        if (matrix[row + i][col + i] != '1') break;
                        for (int j = 0; j < i; j ++) {
                            if (matrix[row + i][col + j] == '0' || matrix[row + j][col + i] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) res = max(res, i + 1);
                        else break;
                    }
                }
            }
        }
        return res * res;
    }
};

// @lc code=end

