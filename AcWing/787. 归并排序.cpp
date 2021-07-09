/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-13 10:01:03
 * @LastEditTime: 2021-07-06 16:46:44
 * @FilePath: \Leetcode\AcWing\787. 归并排序.cpp
 */

// vector 版

# include <bits/stdc++.h>
using namespace std;

int n;
vector<int> q;
vector<int> tmp;

void merge_sort(vector<int>& q, int l, int r) {
    if (l >= r) return;
    int mid = r + l >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        tmp[k ++] = q[i] < q[j] ? q[i ++] : q[j ++];
    }
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];
    
    for (i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    q.resize(n);
    tmp.resize(n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}






# include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) 
        tmp[k ++] = q[i] <= q[j] ? q[i ++] : q[j ++];
    
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];
    
    for (i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}