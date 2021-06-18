/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-07 17:01:04
 * @LastEditTime: 2021-03-08 14:38:33
 * @FilePath: \Leetcode\132.Palindrome Partitioning II.cpp
 */
/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
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
TIME:     52ms    BEAT: 51.55%    O(n) = n^2
MEMORY: 19.2MB    BEAT: 24.69%    O(n) = n^2
LAST EDIT TIME: 2021年3月8日13:48:46
Description: 
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, true));
        for (int j = 1; j < n; j ++) {
            for (int i = 0; i < j; i ++) {
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<int> f(n);    // f(n) 代表考虑下标为 i 的字符为结尾的最小分割次数
        for (int j = 1; j < n; j ++) {
            if (dp[0][j]) f[j] = 0;    // 如果这一段直接构成回文，则无须分隔。
            // 如果无法构成回文。
            else {
                // 1、独立使用一次分隔次数。
                f[j] = f[j - 1] + 1;
                // 2、第 j 个字符本身不独立使用分割次数
                // 代表要与前面的某个位置 i 形成区间 [i,j]，使得 [i, j] 形成回文，[i, j] 整体消耗一次分割次数
                for (int i = 1; i < j; i ++) {
                    if (dp[i][j]) f[j] = min(f[j], f[i - 1] + 1);    // 这一行有点绕
                }
            }
        }
        return f[n - 1];
    }
};


/*
RESULT: Time Out
LAST EDIT TIME: 2021年3月7日20:19:28
*/

class Solution {
private:
    vector<vector<int>> dp;
    int res = INT_MAX;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            res = ans.size() < res ? ans.size() : res;
            return;
        }
        for (int j = i; j < n; j ++) {
            if (dp[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    int minCut(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, true));

        for (int j = 1; j < n; j ++) {
            for (int i = 0; i < j; i ++) {
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        dfs(s, 0);
        return res;
    }

    int isPalindrome(const string& s, int i, int j) {
        if (dp[i][j]) {
            return dp[i][j];
        }
        if (i >= j) {
            return dp[i][j] = 1;
        }
        return dp[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }
};

// @lc code=end

