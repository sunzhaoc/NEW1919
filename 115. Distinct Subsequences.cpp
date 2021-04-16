/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 12:58:49
 * @LastEditTime: 2021-03-17 13:29:37
 * @FilePath: \Leetcode\115.Distinct Subsequences.cpp
 */
/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.2MB    BEAT:  52.95%    O(n) = 
LAST EDIT TIME: 2021年3月17日13:27:4
Description: 
https://leetcode-cn.com/problems/distinct-subsequences/solution/dong-tai-gui-hua-by-powcai-5/
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(t.length() + 1, vector<long> (s.length() + 1, 0));
        
        for (int i = 0; i < s.length(); i ++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= t.length(); i ++) {
            for (int j = 1; j <= s.length(); j ++) {
                if (s[j - 1] == t[i - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        
        return dp.back().back();
    }
};

// @lc code=end

