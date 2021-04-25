/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 15:19:27
 * @LastEditTime: 2021-03-29 15:19:28
 * @FilePath: \Leetcode\HUAWEI\HJ6.cpp
 */
# include <iostream>
# include <math.h> 
using namespace std;

int main() {
    long x;
    while (cin >> x) {
        for (int i = 2; i <= sqrt(x); i ++) {
            while (x % i == 0) {
                x /= i;
                cout << i << ' ';
            }
        }
        if (x > 1) cout << x << ' ';
    }
    return 0;
}