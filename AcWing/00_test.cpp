/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 21:59:52
 * @LastEditTime: 2021-04-25 21:59:52
 * @FilePath: \Leetcode\AcWing\00_test.cpp
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
