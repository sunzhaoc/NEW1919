/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 21:29:35
 * @LastEditTime: 2021-03-24 21:29:35
 * @FilePath: \Leetcode\HUAWEI\HJ100.cpp
 */
#include <iostream>
using namespace std;

int main() {
    int x;
    int a = 2;
    int gap = 3;
    while (cin >> x) {
        cout << (2 + 2 + 3 * (x - 1)) * x / 2 <<endl;
    }
    return 0;
}