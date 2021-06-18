/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-17 20:03:24
 * @FilePath: \Leetcode\AcWing\849. Dijkstra求最短路 I.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i ++) {// 总共需要遍历n遍，每次确定一个点。
        // 在还未确定最短路的点中，寻找距离最小的点
        int t = -1;
        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        st[t] = true;
        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
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
    int t = dijkstra();
    cout << t << endl;
    return 0;
}