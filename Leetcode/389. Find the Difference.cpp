/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-18 12:43:34
 * @LastEditTime: 2020-12-18 13:10:01
 * @FilePath: \Leetcode\389.Find the Difference.cpp
 */
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 73.81%    O(n) = n
MEMORY: 6.9MB    BEAT: 21.88%    O(n) = 1
Description: 位运算。
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (char ch: s)    res ^= ch;
        for (char ch: t)    res ^= ch;
        return res;
        }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 73.81%    O(n) = n
MEMORY: 6.8MB    BEAT: 45.80%    O(n) = 1
Description: 求和。
*/

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int sum_s = 0, sum_t = 0;
//         for (char temp: s) sum_s += temp;
//         for (char temp: t) sum_t += temp;
//         return sum_t - sum_s;
//     }
// };


int main() {
    Solution sol;
    char ans = sol.findTheDifference("abcd", "abcde");
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

