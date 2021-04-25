/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 15:08:20
 * @LastEditTime: 2021-03-25 15:08:21
 * @FilePath: \Leetcode\HUAWEI\HJ2.cpp
 */
#include <iostream>
using namespace std;

int main() {
    string s;
    char a;
    getline(cin, s);
    cin >> a;
    int res = 0;
    for (auto x: s) {
        if (x == a || x - 32 == a || x + 32 == a) res ++;
    }
    cout << res;
    return 0;
}