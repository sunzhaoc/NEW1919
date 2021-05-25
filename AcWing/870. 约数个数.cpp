/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 14:00:58
 * @LastEditTime: 2021-05-25 14:05:40
 * @FilePath: \Leetcode\AcWing\870. 约数个数.cpp
 */
# include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n;
    unordered_map<int, int> m;
    while (n --) {
        cin >> x;
        for (int i = 2; i <= x / i; i ++) {
            while (x % i == 0) {
                x /= i;
                m[i] ++;
            }
        }
        if (x > 1) m[x] ++;
    }

    long long res = 1;
    for (auto it: m) res = res * (it.second + 1) % MOD;
    cout << res % MOD << endl;
    return 0;
}