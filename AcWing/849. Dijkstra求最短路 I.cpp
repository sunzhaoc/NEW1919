/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-08 09:40:29
 * @FilePath: \Leetcode\AcWing\849. Dijkstra求最短路 I.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N]; 

int dijstra() {
    memset(dist, INT_MAX, sizeof dist);    // 11 1111
    dist[1] = 0;
    for (int i = 0; i < n; i ++) { // 总共需要遍历n遍。
        // 在还未确定最短路的点中，寻找距离最小的点
        int t = -1;
        for (int j = 1; j <= n; j ++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        st[t] = true;
        
        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == INT_MAX) return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    int t = dijstra();
    printf("%d\n", t);
    return 0;
}