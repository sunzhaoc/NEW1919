/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-17 19:41:28
 * @FilePath: \Leetcode\AcWing\850. Dijkstra求最短路 II.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N]; 
int idx = 0;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijstra() {
    memset(dist, 0x3f, sizeof dist);    // 11 1111
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 1});  // 距离是0，编号是1

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    // int t = dijstra();
    // printf("%d\n", t);
    int tmp = 0;
    return 0;
}