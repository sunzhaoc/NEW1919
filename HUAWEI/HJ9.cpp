/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-23 20:39:31
 * @LastEditTime: 2021-03-23 20:39:32
 * @FilePath: \Leetcode\HUAWEI\HJ9.cpp
 */
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int x;
    cin >> x;
    string res = "";
    unordered_set<char> s;
    string st = to_string(x);
    for (int i = st.length() - 1; i >= 0; i --) {
        if (s.find(st[i]) == s.end()) {
            s.insert(st[i]);
            res += st[i];
        }
    }
    cout << res << endl;
    return 0;
}