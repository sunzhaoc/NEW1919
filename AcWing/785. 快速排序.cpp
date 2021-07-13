/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-12 10:06:16
 * @LastEditTime: 2021-07-13 09:12:37
 * @FilePath: \Leetcode\AcWing\785. 快速排序.cpp
 */

# include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    
    quick_sort(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}


/*
 * vector版。  
 */

# include<bits/stdc++.h>
using namespace std;

int n;
vector<int> q;

void quick_sort(vector<int>& q, int l, int r) {
    if (l >= r) return;
    
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    q.resize(n);
    
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}