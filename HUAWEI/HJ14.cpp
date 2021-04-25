/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-23 20:44:55
 * @LastEditTime: 2021-03-23 20:44:55
 * @FilePath: \Leetcode\HUAWEI\HJ14.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> st(n);
    for (int i = 0; i < n; i ++) cin >> st[i];
    sort(st.begin(),st.end());
    for (int i = 0; i < n; i ++) cout << st[i] << endl;
    return 0;
}