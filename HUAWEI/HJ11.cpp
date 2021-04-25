/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-23 20:27:52
 * @LastEditTime: 2021-03-23 20:28:03
 * @FilePath: \Leetcode\HUAWEI\HJ11.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x;
    cin >> x;
    string st = to_string(x);
    reverse(st.begin(), st.end());
    cout << st << endl;
     
    return 0;
}