/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-21 15:14:19
 * @LastEditTime: 2020-12-21 15:40:31
 * @FilePath: \Leetcode\372.Super Pow.cpp
 */
/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     28ms    BEAT: 50.17%    O(n) = 
MEMORY: 11.9MB    BEAT: 13.99%    O(n) = 
Description: 快速幂运算 + 递归。
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = myPow(a, last);
        int part2 = myPow(superPow(a, b), 10);

        return (part1 * part2) % 1337;
    }

private:
    int myPow(int a, int k) {
        a %= 1337;
        int res = 1;
        for (int _ = 0; _ < k; _ ++) {
            res *= a;
            res %= 1337;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> b = {3};
    int ans = sol.superPow(2, b);
    cout << ans << endl;
    return 0;
}

// @lc code=end

