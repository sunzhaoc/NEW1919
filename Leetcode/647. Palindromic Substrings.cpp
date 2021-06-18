/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-22 20:36:07
 * @LastEditTime: 2021-03-22 20:54:34
 * @FilePath: \Leetcode\647.Palindromic Substrings.cpp
 */
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
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

// 可以使用 Manacher算法。

/*
RESULT: Accept
TIME:     28ms    BEAT: 27.13%    O(n) = 
MEMORY: 19.5MB    BEAT: 17.47%    O(n) = 
USED TIME: 14:07
LAST EDIT TIME: 2021年3月22日20:51:30
Description: 
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        // int dp[n][n];
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int res = 0;
        for (int i = 0; i < n; i ++) {
            dp[i][i] = 1;
        }
        for (int j = 1; j < n; j ++) {
            for (int i = j - 1; i >= 0; i --) {
                if (s[i] != s[j]) dp[i][j] = 0;
                else if (j - i < 3) dp[i][j] = 1;
                else dp[i][j] = dp[i + 1][j - 1];
            }
        }

        for (int j = 0; j < n; j ++) {
            for (int i = 0; i <= j; i ++) {
                res = dp[i][j] == 1 ? res + 1 : res;
            }
        }

        return res;
    }
};

// @lc code=end

