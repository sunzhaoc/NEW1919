/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-27 10:32:25
 * @LastEditTime: 2021-04-27 10:33:35
 * @FilePath: \Leetcode\150. Evaluate Reverse Polish Notation.cpp
 */
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

/*
RESULT: Accept
TIME:      8ms    BEAT: 93.72%    O(n) = 
MEMORY: 11.6MB    BEAT: 79.44%    O(n) = 
LAST EDIT TIME: 2021年4月27日10:33:1
Description: 
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& ele: tokens) {
            if (ele != "+" && ele != "-" && ele != "*" && ele != "/") {
                st.push(stoi(ele));
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (ele == "+") st.push(a + b);
                else if (ele == "-") st.push(b - a);
                else if (ele == "*") st.push(a * b);
                else if (ele == "/") st.push(b / a);
            }
        }
        return st.top();
    }
};

// @lc code=end

