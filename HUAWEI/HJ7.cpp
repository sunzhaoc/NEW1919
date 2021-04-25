/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 15:28:12
 * @LastEditTime: 2021-03-29 15:28:12
 * @FilePath: \Leetcode\HUAWEI\HJ7.cpp
 */
# include <iostream>
using namespace std;

int main() {
    float x;
    while (cin >> x) {
        int i = x * 10;
        i %= 10;
        if (i >= 5) cout << (int)x + 1 << endl;
        else cout << int(x) << endl;
    }
    return 0;
}