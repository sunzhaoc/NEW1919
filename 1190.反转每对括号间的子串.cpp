/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-26 09:07:24
 * @LastEditTime: 2021-05-26 09:08:10
 * @FilePath: \Leetcode\1190.反转每对括号间的子串.cpp
 */
/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.5MB    BEAT:  37.88%    O(n) = 
LAST EDIT TIME: 2021年5月26日9:7:53
Description: 
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string res;
        for (auto& ch: s) {
            if (ch == '(') {
                stk.push(res);
                res = "";
            }
            else if (ch == ')') {
                reverse(res.begin(), res.end());
                res = stk.top() + res;
                stk.pop();
            }
            else res += ch;
        }
        return res;
    }
};
// @lc code=end

