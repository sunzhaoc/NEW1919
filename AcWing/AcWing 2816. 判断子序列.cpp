/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-06-02 10:10:38
 * @LastEditTime: 2021-06-02 10:10:52
 * @FilePath: \Leetcode\AcWing\AcWing 2816. 判断子序列.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];
    int l = 0, r = 0;
    while (l < n && r < m) {
        while (r < m && a[l] != b[r]) r ++;
        l ++;
        r ++;
    }
    if (l < n || (l == n && r == m && a[n - 1] != b[m - 1])) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}