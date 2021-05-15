/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-14 09:55:23
 * @LastEditTime: 2021-05-14 09:55:24
 * @FilePath: \Leetcode\AcWing\788. 逆序对的数量.cpp
 */
# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q[N], tmp[N];

long long merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;
    
    int mid = l + r >> 1;
    long long res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
     
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] > q[j]) {
            res += (mid - i + 1);
            tmp[k ++] = q[j ++];
        }
        else tmp[k ++] = q[i ++];
    }
    
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];
    
    for (i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    cout << merge_sort(q, 0, n - 1);
    return 0;
}
