/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-23 20:33:38
 * @LastEditTime: 2021-03-23 20:33:39
 * @FilePath: \Leetcode\HUAWEI\HJ10.cpp
 */
#include <iostream>
#include<unordered_set>
using namespace std;

int main() {
    string st;
    cin >> st;
    unordered_set<char> charSet;
    for (auto c: st) {
        charSet.insert(c);
    }
    cout << charSet.size() << endl;
    return 0;
}