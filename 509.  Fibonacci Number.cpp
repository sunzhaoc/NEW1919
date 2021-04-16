/*
 * @Description:
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-04 08:58:56
 * @LastEditTime: 2021-01-04 09:07:15
 * @FilePath: \Leetcode\509. Fibonacci Number.cpp
 */
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:   0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6MB    BEAT:  74.64%    O(n) = 1
Description: 
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int A = 0, B = 1, ans = 0;
        for (int i = 2; i <= n; i ++) {
            ans = A + B;
            A = B;
            B = ans;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    int ans = sol.fib(4);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

