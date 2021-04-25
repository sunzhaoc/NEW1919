/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-21 14:37:42
 * @LastEditTime: 2020-12-21 22:39:18
 * @FilePath: \Leetcode\50.pow-x-n.cpp
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = log n
MEMORY: 6.1MB    BEAT:  45.14%    O(n) = log n
Description: 快速幂运算 + 递归。
*/

class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? qucikMul(x, n) : 1.0 / qucikMul(x, n);
    }

private:
    double qucikMul(double x, int n) {
        if (n == 0) return 1.0;
        double ans = qucikMul(x , n / 2);
        return n % 2 == 0 ? ans * ans : ans * ans * x;
    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
Description: 
*/

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n == 0) return 1;
//         double ans = 1;
//         for (int i = 0; i < abs(n); i ++) {
//             ans *= x;
//         }
//         if (n < 0) return 1/ans;
//         return ans;
//     }
// };


int main() {
    Solution sol;
    // double ans = sol.myPow(2.00000, 10);
    // double ans = sol.myPow(2.10000, 3);
    // double ans = sol.myPow(2.0, -2);
    double ans = sol.myPow(0.00001, 2147483647);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

