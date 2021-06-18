
/*
Description: 01背包的二维vector写法。时空复杂度都是O(NV)
*/
# include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    
    for (int i = 1; i <= N; i ++) { // 考虑前i个物品
        for (int j = 1; j <= V; j ++) { // 考虑背包为j的情况
            if (j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    
    cout << dp.back().back() << endl;
    return 0;
}


/*
Description: 01背包的一维vector写法。时间复杂度O(NV)，空间复杂度O(V)
这个是最常用的版本。
*/
# include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    
    vector<int> dp(V + 1, 0);
    
    for (int i = 1; i <= N; i ++) { // 考虑前i个物品
        for (int j = V; j >= v[i]; j --) { // 考虑背包为j的情况，注意这里是倒序遍历背包容量
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    cout << dp.back() << endl;
    return 0;
}


/*
Description: 01背包的一维vector写法。时间复杂度O(NV)，空间复杂度O(V)，加了一个常数优化 + 后缀和。
*/
# include<bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 1, 0), w(N + 1, 0);
    for (int i = 1; i <= N; i ++) cin >> v[i] >> w[i];
    
    vector<int> dp(V + 1, 0);
    
    // 后缀和优化
    vector<int> preSum(N + 1);
    preSum.back() = v.back();
    for (int i = v.size() - 2; i >= 1; i --) preSum[i] = preSum[i + 1] + v[i];
    
    for (int i = 1; i <= N; i ++) { // 考虑前i个物品
        for (int j = V; j >= max(v[i], V - preSum[i]); j --) { // 考虑背包为j的情况，常数优化。
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    
    cout << dp.back() << endl;
    return 0;
}



/*
Description: 01背包的二维vector写法。时空复杂度都是O(NV)。
附加条件是：要求背包恰好装满。初始化F[0] = 0, F[1...V] = INT_MIN （即第一列为0，其余列为INT_MIN）
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

