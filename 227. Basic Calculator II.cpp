/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-10 09:06:02
 * @LastEditTime: 2021-03-10 09:35:33
 * @FilePath: \Leetcode\227.Basic Calculator II.cpp
 */
/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
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
TIME:    20ms    BEAT: 37.61%    O(n) = 
MEMORY: 9.2MB    BEAT: 18.23%    O(n) = 
USED TIME: 27:20
LAST EDIT TIME: 2021年3月10日9:34:49
Description: Easy啦。还好想出来了。
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        stack<int> num;
        ops.push(1);
        int i = 0;
        long res = 0;
        int cal = 0;
        while (i < s.length()) {
            if (s[i] == ' ') i ++;
            else if (s[i] == '+') {
                ops.push(1);
                i ++;
            }
            else if (s[i] == '-') {
                ops.push(-1);
                i ++;
            }
            else if (s[i] == '*') {
                cal = 1;
                i ++;
            }
            else if (s[i] == '/') {
                cal = 2;
                i ++;
            }
            else {
                long tmp = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    tmp = tmp * 10 + s[i] - '0';
                    i ++;
                }
                if (cal == 1) {
                    tmp = tmp * num.top();
                    num.pop();
                    cal = 0;
                }
                else if (cal == 2) {
                    tmp = num.top() / tmp;
                    num.pop();
                    cal = 0;
                }
                num.push(tmp);
            }
        }
        while (!ops.empty()) {
            res += ops.top() * num.top();
            ops.pop();
            num.pop();
        }
        return res;
    }
};


int main() {
    Solution sol;
    int ans = sol.calculate("3+2*2");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

