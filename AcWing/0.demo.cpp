/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-17 20:36:03
 * @FilePath: \Leetcode\AcWing\0.demo.cpp
 */

# include<bits/stdc++.h>
using namespace std;


int main() {
    int V, N;
    cin >> V;
    vector<int> v, w;
    int tmp;
    while (cin >> tmp) {
        v.push_back(tmp);
    }
    while (cin >> tmp) {
        w.push_back(tmp);
    }
    
    N = v.size();
    
    vector<int> dp(V + 1, 0);

    vector<int> preSum(N + 1);
    preSum.back() = v.back();
    for (int i = v.size() - 2; i >= 1; i --) preSum[i] = preSum[i + 1] + v[i];
    
    for (int i = 1; i <= N; i ++) {
        for (int j = V; j >= max(v[i], V - preSum[i]); j --) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp.back() << endl;
    system("pause");
    return 0;
}