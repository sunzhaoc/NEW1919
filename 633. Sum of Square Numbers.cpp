/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-21 15:44:07
 * @LastEditTime: 2020-12-21 21:30:46
 * @FilePath: \Leetcode\633.Sum of Square Numbers.cpp
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  22.65%    O(n) = 
Description: 
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = sqrt(c);    // 该处的r如果不用sqrt()函数，其实是由二分法得到。
        while (l <= r) {
            if (l * l + r * r == c) return true;
            else if (l * l + r * r > c) r --;
            else l ++;
        }
        return false;
    }
};


/*
RESULT: WRONG
TIME:   ms    BEAT: %    O(n) = sqrt(n)
MEMORY: MB    BEAT: %    O(n) = 1
Description: 利用sqrt函数。能运行但提交报错。
*/

// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         double temp;
//         for (int i = 0; i <= c; i ++) {
//             temp = sqrt(c - i *i);
//             if (temp == (int)temp) return true;
//         }
//         return false;
//     }
// };


int main() {
    Solution sol;
    bool ans = sol.judgeSquareSum(61);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

