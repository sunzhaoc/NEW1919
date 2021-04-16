/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-12 20:10:58
 * @LastEditTime: 2021-03-19 10:53:42
 * @FilePath: \Leetcode\5.Longest Palindromic Substring.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

/*
Manacher算法:
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/tu-jie-ma-la-che-suan-fa-by-wang_ni_ma-if33/
*/


/*
RESULT: Accept
TIME:   200ms    BEAT: 55.50%    O(n) = mn
MEMORY: 7.9MB    BEAT: 77.56%    O(n) = n^2
USED TIME: 09:56
LAST EDIT TIME: 2021年3月19日10:47:49
Description: 二刷。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 1) return s;

        int maxLen = 1;
        int beginIndex = 0;

        bool dp[len][len];
        
        for (int i = 0; i < len; i ++) dp[i][i] = true;

        for (int j = 1; j < len; j ++) {
            for (int i = 0; i < j; i ++) {
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    beginIndex = i;
                }
            }
        }

        return s.substr(beginIndex, maxLen);
    }
};


/*
RESULT: Accept
TIME:   256ms    BEAT: 53.56%    O(n) = n^2
MEMORY: 8.4MB    BEAT: 75.34%    O(n) = n^2
Description: DP。
使用数组定义DP能通过，使用vector会报超时。
在国际版中均能AC，使用数组140ms，使用vector 588ms。
*/

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int len = s.length();
//         if (len == 1) return s;

//         int maxLen = 1;
//         int begin = 0;
        
//         bool dp[len][len];
//         // vector<vector<bool>> dp(len, vector<bool>(len));
//         for (int i = 0; i < len; i ++) dp[i][i] = true;

//         for (int j = 1; j < len; j ++) {
//             for (int i = 0; i < j; i ++) {
//                 if (s[i] != s[j]) dp[i][j] = false;
//                 else {
//                     if (j - i < 3) dp[i][j] = true;
//                     else dp[i][j] = dp[i + 1][j - 1];
//                 }

//                 if (dp[i][j] && j - i + 1 > maxLen) {
//                     maxLen = j - i + 1;
//                     begin = i;
//                 }
//             }
//         }

//         return s.substr(begin, maxLen);
//     }
// };


/*
RESULT: Accept
TIME:     268ms    BEAT: 52.94%    O(n) = n^2
MEMORY: 234.5MB    BEAT: 38.85%    O(n) = 1
USED TIME: 19:37
Description: 中心扩展法。注意偶数和奇数的情况，这两种可以合并成一种。
也可以借鉴Manacher算法中添加分隔符#的方法，使奇偶变为一种情况。
*/

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.length() == 1) return s;

//         vector<int> res(3), tmp(3);
//         int len = 1;
//         for (int i = 1; i < s.length(); i ++) {
//             tmp = fun(s, i, i);
//             if (tmp[2] >= len) {
//                 res = tmp;
//                 len = tmp[2];
//             }
//             tmp = fun(s, i - 1, i);
//             if (tmp[2] >= len) {
//                 res = tmp;
//                 len = tmp[2];
//             }
//         }

//         string ans = "";
//         for (int i = res[0]; i <= res[1]; i ++) {
//             ans += s[i];
//         }
//         return ans;
//     }

// private:
//     vector<int> fun(string s, int mid1, int mid2) {
//         int x = 0;

//         while (mid1 - x >= 0 && mid2 + x < s.length() && s[mid1 - x] == s[mid2 + x]) x ++;

//         if (mid1 == mid2) return {mid1 - x + 1, mid2 + x - 1, 2 * x - 1};
//         else return {mid1 - x + 1, mid2 + x - 1, 2 * x};
//     }
// };


int main() {
    Solution sol;
    // string ans = sol.longestPalindrome("babad");
    // string ans = sol.longestPalindrome("cbbd");
    string ans = sol.longestPalindrome("a");
    // string ans = sol.longestPalindrome("ac");
    // string ans = sol.longestPalindrome("aaaa");
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

