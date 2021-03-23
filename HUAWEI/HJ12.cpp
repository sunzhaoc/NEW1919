/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-23 20:23:26
 * @LastEditTime: 2021-03-23 20:23:43
 * @FilePath: \Leetcode\华为机试\HJ12.cpp
 */
# include <iostream>
using namespace std;

string fun(string st) {
    string res;
    for (int i = st.length() - 1; i >= 0; i --) {
        res += st[i];
    }
    return res;
}

int main() {
    string st;
    cin >> st;
    string res = fun(st);
    cout << res << endl;
    return 0;
}