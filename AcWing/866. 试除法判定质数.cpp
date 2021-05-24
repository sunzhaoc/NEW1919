/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-24 15:53:12
 * @LastEditTime: 2021-05-24 15:53:12
 * @FilePath: \Leetcode\AcWing\866. 试除法判定质数.cpp
 */
# include<bits/stdc++.h> 
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++) if (x % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        if (is_prime(a[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}