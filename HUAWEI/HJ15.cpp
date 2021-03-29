/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-29 16:01:10
 * @LastEditTime: 2021-03-29 16:01:11
 * @FilePath: \Leetcode\HUAWEI\HJ15.cpp
 */
# include <iostream>
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