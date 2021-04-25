/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 16:04:03
 * @LastEditTime: 2021-03-29 16:04:03
 * @FilePath: \Leetcode\HUAWEI\HJ62.cpp
 */
# include <iostream>
# include <string>
using namespace std;

int main() {
    int x;
    while (cin >> x) {
        int res = 0;
        while (x) {
            res += x & 1;
            x >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}