/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-01 15:37:26
 * @LastEditTime: 2021-03-01 16:09:22
 * @FilePath: \Leetcode\20.Valid Parentheses.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1MB    BEAT:  86.65%    O(n) =  
LAST EDIT TIME: 2021年3月1日16:2:23
Description: 本以为必须是{[()]}的顺序，其实([{}])这种也是对的。。。那没事了。
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        unordered_map<char, int> map{{'(', 1},
                                     {'[', 2},
                                     {'{', 3},
                                     {')', 4},
                                     {']', 5},
                                     {'}', 6}};
        stack<char> st;
        bool tmp = true;
        for (char ch: s) {
            int flag = map[ch];
            if (flag >= 1 && flag <= 3) st.push(ch);
            else if (!st.empty() && map[st.top()] == flag - 3) st.pop();
            else {
                tmp = false;
                break;
            }
        }

        if (!st.empty()) tmp = false;
        return tmp;
    }
};

// @lc code=end

