/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-03 20:10:11
 * @LastEditTime: 2021-04-04 14:50:49
 * @FilePath: \Leetcode\1143.Longest Common Subsequence.cpp
 */
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
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
TIME:     24ms    BEAT: 77.54%    O(n) = 
MEMORY: 12.8MB    BEAT: 22.99%    O(n) = 
USED TIME: 03:42
LAST EDIT TIME: 2021年4月3日20:33:45
Description: 看着答案写的。以前好像写过。
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1));
        for (int i = 1; i <= text1.length(); i ++) {
            char c1 = text1[i - 1];
            for (int j = 1; j <= text2.length(); j ++) {
                char c2 = text2[j - 1];
                if (c1 == c2) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp.back().back();
    }
};

// @lc code=end

