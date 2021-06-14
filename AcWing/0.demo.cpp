/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-08 10:52:31
 * @FilePath: \Leetcode\AcWing\0.demo.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N];
int dist[N];
bool st[N]; 
int idx = 0;


void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int tmp = 0;
    return 0;
}