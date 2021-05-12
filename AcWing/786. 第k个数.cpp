/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-12 10:30:38
 * @LastEditTime: 2021-05-12 11:05:49
 * @FilePath: \Leetcode\AcWing\786. 第k个数.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quick_sort(int l, int r, int k) {
    if (l == r) return q[l];
    
    int x = q[l], i = l - 1, j = r + 1;
    
    while (i < j) {
        while (q[++ i] < x);
        while (q[-- j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    
    int s1 = j - l + 1;
    if (k <= s1) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - s1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> q[i];
    cout << quick_sort(0, n - 1, k) << endl;
    return 0;
}
