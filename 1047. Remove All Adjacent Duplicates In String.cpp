/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 08:46:55
 * @LastEditTime: 2021-03-09 08:47:30
 * @FilePath: \Leetcode\1047.删除字符串中的所有相邻重复项.cpp
 */
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
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
Description: 
*/

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;

        int i = 0;
        while (i < S.length()) {
            if (st.empty() || S[i] != st.top()) {
                st.push(S[i]);
                i ++;
            }
            else {
                st.pop();
                i ++;
            }
        }

        
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

