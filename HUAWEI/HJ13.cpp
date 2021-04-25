/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 15:58:52
 * @LastEditTime: 2021-03-29 15:58:53
 * @FilePath: \Leetcode\HUAWEI\HJ13.cpp
 */
# include <iostream>
# include <string>
# include <stack>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        stack<string> st;
        int l = 0;
        int r = 0;
        while (r < s.length()) {
            if (s[r] == ' ') {
                st.push(s.substr(l, r - 1 - l + 1));
                r ++;
                l = r;
            }
            else if (s[r] != ' ') {
                if (r == s.length() - 1) {
                    st.push(s.substr(l, r - l + 1));
                    break;
                }
                r ++;
            }
        }
        string res;
        while (st.size()) {
            res += st.top();
            st.pop();
            if (st.size()) res += ' ';
        }
        cout << res << endl;
    }
    return 0;
}