/*
 * @Description:  
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-09 10:28:43
 * @LastEditTime: 2021-03-24 09:37:03
 * @FilePath: \Leetcode\62.Unique Paths.cpp
 */
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description: 数学知识。组合数学。
从左上到右下，共需要走m+n-2步。其中有m-1次向下，n-1次向右。
因此路径的总数等于，从m+n-2次移动中选择m-1次向下移动的方案数。即C(m - 1)(m + n - 2);
= (m + n - 2)! / (m - 1)!(n - 1)!
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = 0; i < )
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 29.88%    O(n) = mn
MEMORY: 5.8MB    BEAT: 87.55%    O(n) = mn
USED TIME: 03:45
LAST EDIT TIME: 2021年3月24日9:26:47
Description: DP。二刷。
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i ++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i ++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = m
MEMORY: 6.3MB    BEAT:  61.38%    O(n) = 1 
LAST EDIT TIME: 2020年12月09日10:40:15
Description: 利用数学组合数知识解决。因为m，n可互换，利用这点可以降低运算时间。
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long sum_up = 1;
        long long sum_down = 1;

        int max = (n >= m)? n : m;
        int min = (n <= m)? n : m;
        for (int i = max; i < min + max - 2 + 1; i ++) {
            sum_up = i * sum_up;
        }
        for (int i = 1; i < min - 1 + 1; i ++) {
            sum_down = i * sum_down;
        }
        return sum_up / sum_down;
    }
};


int main() {
    Solution sol;
    int A = sol.uniquePaths(3, 2);
    cout << A << endl;
    system("pause");
    return 0;
}

// @lc code=end

