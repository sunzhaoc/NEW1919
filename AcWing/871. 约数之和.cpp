/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 14:35:06
 * @LastEditTime: 2021-05-25 14:35:06
 * @FilePath: \Leetcode\AcWing\871. 约数之和.cpp
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
    for (auto it: m) {
        int p = it.first, a = it.second;
        long long t = 1;
        while (a --) t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }
    cout << res << endl;
    return 0;
}