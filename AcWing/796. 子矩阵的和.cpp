/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 15:00:50
 * @LastEditTime: 2021-04-30 15:00:50
 * @FilePath: \Leetcode\AcWing\796. 子矩阵的和.cpp
 */
# include <bits/stdc++.h>
using namespace std;

int nums[1000][1000];
int preSum [1001][1001];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) cin >> nums[i][j];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + nums[i][j];
        }
    }
    
    int x1, y1, x2, y2;
    for (int i = 0; i < q; i ++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << preSum[x2][y2] - preSum[x2][y1 - 1] - preSum[x1 - 1][y2] + preSum[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}