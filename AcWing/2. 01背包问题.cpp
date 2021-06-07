/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 21:20:27
 * @LastEditTime: 2021-04-25 22:39:08
 * @FilePath: \Leetcode\AcWing\2. 01背包问题.cpp
 */

/*
Description: 01背包的二维数组写法。时空复杂度都是O(NV)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    int f[N + 1][V + 1];
    int v[N + 1], w[N + 1];
    for (int i = 1; i <= N; ++ i) cin >> v[i] >> w[i];
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j <= V; j ++) {
            if (i == 0 || j == 0) f[i][j] = 0;
            else if (j < v[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[N][V] << endl;
    return 0;
}


/*
Description: 01背包的二维数组写法。时间复杂度O(NV)，空间复杂度O(V)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    int f[V + 1];
    int v[N + 1], w[N + 1];
    for (int i = 1; i <= N; ++ i) cin >> v[i] >> w[i];
    for (int i = 0; i <= N; i ++) {
        for (int j = V; j >= 0; j --) { // 主要是这一行。应该递减顺序计算。
            if (i == 0 || j == 0) f[j] = 0;
            else if (j < v[i]) f[j] = f[j];
            else f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}