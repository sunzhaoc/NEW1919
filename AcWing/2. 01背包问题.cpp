/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 21:20:27
 * @LastEditTime: 2021-04-25 22:39:08
 * @FilePath: \Leetcode\AcWing\2. 01背包问题.cpp
 */

/*
Description: 01背包的二维vector写法。时空复杂度都是O(NV)。附加条件是：要求背包恰好装满。初始化F[0] = 0, F[1...V] = INT_MIN （即第一列为0，其余列为INT_MIN）
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, INT_MIN));
    for (int i = 0; i < dp.size(); i ++) dp[i][0] = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= V; j ++) {
            if (j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp.back().back() << endl;
    return 0;
}


/*
Description: 01背包的二维vector写法。时空复杂度都是O(NV)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= V; j ++) {
            if (j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp.back().back() << endl;
    return 0;
}


/*
Description: 01背包的二维vector写法。时间复杂度O(NV)，空间复杂度O(V)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= N; i ++) {
        for (int j = V; j >= 0; j --) {
            if (j < v[i]) dp[j] = dp[j];
            else dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp.back() << endl;
    return 0;
}


/*
Description: 01背包的二维vector写法。时间复杂度O(NV)，空间复杂度O(V)，加了一个常数优化 + 前缀和。
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    vector<int> dp(V + 1, 0);
    // 用前缀和方便以后计算
    vector<int> preSum(N + 1);
    preSum.back() = v.back();
    for (int i = v.size() - 2; i >= 0; i --) preSum[i] = preSum[i + 1] + v[i];
    
    for (int i = 1; i <= N; i ++) {
        for (int j = V; j >= max(v[i], V - preSum[i]); j --) { // 常数优化
            if (j < v[i]) dp[j] = dp[j];
            else dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp.back() << endl;
    return 0;
}


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