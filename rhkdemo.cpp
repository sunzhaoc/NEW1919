/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-01 18:58:26
 * @LastEditTime: 2021-04-01 19:45:50
 * @FilePath: \Leetcode\rhkdemo.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

typedef long long LL;

int qmi(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % 1000000007;
        a = (LL)a * a % 1000000007;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    const int N = 1000000007;
    while (cin >> n) {
        n = n % N;
        cout << n << endl;  // 1
        cout << (n * 2 - 1) % N << endl;    // 2
        cout << (n * n) % N << endl; // 3

        // 4
        LL A = qmi(2, n - 1) % N;
        cout << A << endl;

        // 5
        A = (qmi(2, A)) % N;
        cout << A << endl;

        // 6
        cout << ((n + 1) % 2 + 1) % N << endl;

        // 7
        LL res = 0;
        for (int i = 0; i < n; i ++) {
            res = (res * 10 + 1) % N;
        }
        cout << res << endl;
    }
    return 0;
}