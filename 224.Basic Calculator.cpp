/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-10 08:27:58
 * @LastEditTime: 2021-03-10 09:05:30
 * @FilePath: \Leetcode\224.Basic Calculator.cpp
 */
/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
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
TIME:     8ms    BEAT: 92.89%    O(n) = n
MEMORY: 7.9MB    BEAT: 80.31%    O(n) = n
USED TIME: 
LAST EDIT TIME: 2021年3月10日8:52:59
Description: 得稍微仔细想想。
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int res = 0;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == ' ') {
                i ++;
            }
            else if (s[i] == '+') {
                sign = ops.top();
                i ++;
            }
            else if (s[i] == '-') {
                sign = - ops.top();
                i ++;
            }
            else if (s[i] == '(') {
                ops.push(sign);
                i ++;
            }
            else if (s[i] == ')') {
                ops.pop();
                i ++;
            }
            else {
                long num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                res += sign * num;
            }
        }

        return res;
    }
};

// @lc code=end

