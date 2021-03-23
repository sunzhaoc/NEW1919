/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-04 09:09:26
 * @LastEditTime: 2021-03-23 09:44:36
 * @FilePath: \Leetcode\131.Palindrome Partitioning.cpp
 */
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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




class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for (int i = 0; i < n; i ++) {
            dp[i][i] = false;
        }
        
    }
};


/*
RESULT: Accept
TIME:   152ms    BEAT: 69.53%    O(n) = n2^n
MEMORY:  74MB    BEAT: 62.14%    O(n) = n^2
LAST EDIT TIME: 2021年3月7日16:53:16
Description: 官解记忆化搜索。
*/

// class Solution {
// private:
//     vector<vector<int>> f;
//     vector<vector<string>> ret;
//     vector<string> ans;
//     int n;

// public:
//     void dfs(const string& s, int i) {
//         if (i == n) {
//             ret.push_back(ans);
//             return;
//         }
//         for (int j = i; j < n; ++j) {
//             if (isPalindrome(s, i, j) == 1) {
//                 ans.push_back(s.substr(i, j - i + 1));
//                 dfs(s, j + 1);
//                 ans.pop_back();
//             }
//         }
//     }

//     // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
//     int isPalindrome(const string& s, int i, int j) {
//         if (f[i][j]) {
//             return f[i][j];
//         }
//         if (i >= j) {
//             return f[i][j] = 1;
//         }
//         return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
//     }

//     vector<vector<string>> partition(string s) {
//         n = s.size();
//         f.assign(n, vector<int>(n));

//         dfs(s, 0);
//         return ret;
//     }
// };


/*
RESULT: Accept
TIME:    144ms    BEAT: 76.00%    O(n) = n2^n
MEMORY: 73.8MB    BEAT: 73.28%    O(n) = n^2
LAST EDIT TIME: 
Description: 官解DP优化简洁很多啊。
*/

// class Solution {
// private:
//     vector<vector<int>> dp;
//     vector<vector<string>> ret;
//     vector<string> ans;
//     int n;

// public:
//     void dfs(const string& s, int i) {
//         if (i == n) {
//             ret.push_back(ans);
//             return;
//         }
//         for (int j = i; j < n; j ++) {
//             if (dp[i][j]) {
//                 ans.push_back(s.substr(i, j - i + 1));
//                 dfs(s, j + 1);
//                 ans.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         n = s.size();
//         dp.assign(n, vector<int>(n, true));

//         for (int j = 1; j < n; j ++) {
//             for (int i = 0; i < j; i ++) {
//                 if (s[i] != s[j]) dp[i][j] = false;
//                 else {
//                     if (j - i < 3) dp[i][j] = true;
//                     else dp[i][j] = dp[i + 1][j - 1];
//                 }
//             }
//         }

//         dfs(s, 0);
//         return ret;
//     }
// };


/*
RESULT: Accept
TIME:     216ms    BEAT: 41.99%    O(n) = 
MEMORY: 146.8MB    BEAT: 10.96%    O(n) = 
LAST EDIT TIME: 2021年3月7日16:17:50
Description: 
加了DP优化，在一开始就算好所有的子串是不是回文串。
*/

// class Solution {
// public:
//     vector<vector<string>> ans = {};
//     vector<vector<int>> dp;
//     vector<vector<string>> partition(string s) {

//         dp.resize(s.length(), vector<int>(s.length()));
//         // bool dp[s.length()][s.length()];
//         for (int i = 0; i < s.length(); i ++) dp[i][i] = true;
//         for (int j = 1; j < s.length(); j ++) {
//             for (int i = 0; i < j; i ++) {
//                 if (s[i] != s[j]) dp[i][j] = false;
//                 else {
//                     if (j - i < 3) dp[i][j] = true;
//                     else dp[i][j] = dp[i + 1][j - 1];
//                 }
//             }
//         }
//         backTrack(s, 0, s.length() - 1, {});
//         return ans;
//     }

//     void backTrack(string& s, int start, int end, vector<string> used) {
//         if (start == end && start == s.length() - 1) {
//             used.emplace_back(s.substr(start, 1));
//             ans.emplace_back(used);
//             used.pop_back();
//             return;
//         }
//         else if (start > end) {
//             ans.emplace_back(used);
//             return;
//         }

//         for (int i = start; i <= end; i ++) {
//             if (dp[start][i]) {
//                 used.emplace_back(s.substr(start, i - start + 1));
//                 backTrack(s, i + 1, end, used);
//                 used.pop_back();
//             }
//         }
//     }
// };


/*
RESULT: Accept
TIME:     224ms    BEAT: 40.20%    O(n) = n2^n
MEMORY: 146.7MB    BEAT: 10.96%    O(n) = n
LAST EDIT TIME: 2021-3-7 16:11:1
Description: 二刷。
参考下面的
https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/
*/

// class Solution {
// public:
//     vector<vector<string>> ans = {};

//     vector<vector<string>> partition(string s) {
//         backTrack(s, 0, s.length() - 1, {});
//         return ans;
//     }

//     void backTrack(string& s, int start, int end, vector<string> used) {
//         if (start == end && start == s.length() - 1) {
//             used.emplace_back(s.substr(start, 1));
//             ans.emplace_back(used);
//             used.pop_back();
//             return;
//         }
//         else if (start > end) {
//             ans.emplace_back(used);
//             return;
//         }

//         for (int i = start; i <= end; i ++) {
//             if (whether_par(s, start, i)) {
//                 used.emplace_back(s.substr(start, i - start + 1));
//                 backTrack(s, i + 1, end, used);
//                 used.pop_back();
//             }
//         }
//     }

//     bool whether_par(string& s, int start, int end) {
//         for (int i = start, j = end; i < j; i ++, j --) {
//             if (s[i] != s[j]) return false;
//         }
//         return true;
//     }
// };


/*
RESULT: Accept
TIME:    300ms    BEAT: 11.40%    O(n) = 
MEMORY: 74.5MB    BEAT: 22.90%    O(n) = 
Description: 递归。传地址，优化。
时空差距并没有那么大。
*/

// class Solution {

// public:
//     vector<vector<string>> res = {};

//     bool whether_par(string& s) {
//         if (s.length() == 1) return true;
//         int n = s.length() - 1;
//         for (int i = 0; i <= n; i ++) {
//             if (s[i] == s[n]) n--;
//             else return false ;
//         }
//         return true;
//     }   

//     void backTrack(const string& unused, vector<string>& used){
//         if (unused.empty()) {
//             res.push_back({used});
//             return;
//         }

//         for (int i = 1; i <= unused.size(); i ++) {
//             string sub_str = unused.substr(0, i);
//             if (whether_par(sub_str)) {
//                 used.push_back(sub_str);
//                 backTrack(unused.substr(i, unused.length() - i), used);
//                 used.pop_back();
//             }
//         }

//         return;
//     }

//     vector<vector<string>> partition(string s) {
//         vector<string> used;
//         backTrack(s, used);
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     420ms    BEAT: 5.13%    O(n) = 
MEMORY: 159.8MB    BEAT: 5.03%    O(n) = 
USED TIME: 01:19:43
Description: 递归。传参数，优化。
*/

// class Solution {

// public:
//     vector<vector<string>> res = {};

//     bool whether_par(string s) {
//         if (s.length() == 1) return true;
//         int n = s.length() - 1;
//         for (int i = 0; i <= n; i ++) {
//             if (s[i] == s[n]) n--;
//             else return false ;
//         }
//         return true;
//     }   

//     void backTrack(string unused, vector<string> used){
//         if (unused.empty()) {
//             res.push_back({used});
//             return;
//         }

//         for (int i = 1; i <= unused.size(); i ++) {
//             if (whether_par(unused.substr(0, i))) {
//                 used.push_back(unused.substr(0, i));
//                 backTrack(unused.substr(i, unused.length() - i), used);
//                 used.pop_back();
//             }
//         }

//         return;
//     }

//     vector<vector<string>> partition(string s) {
//         backTrack(s, {});
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<vector<string>> ans = sol.partition("bb");
    system("pause");
    return 0;
}

// @lc code=end

