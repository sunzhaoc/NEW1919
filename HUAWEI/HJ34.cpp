/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-23 21:40:23
 * @LastEditTime: 2021-03-23 21:40:30
 * @FilePath: \Leetcode\HUAWEI\HJ34.cpp
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string st;
    while (cin >> st) {
        sort(st.begin(), st.end());
        cout << st << endl;
    }
    return 0;
}
