/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 13:47:02
 * @LastEditTime: 2021-04-30 13:47:03
 * @FilePath: \Leetcode\AcWing\795. 前缀和.cpp
 */
# include <bits/stdc++.h>
using namespace std;

int nums[100001];
int preSum[100001];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> nums[i];
    long long sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum += nums[i];
        preSum[i] = sum;
    }
    int l, r;
    while (cin >> l >> r) {
        cout << preSum[r] - preSum[l - 1] << endl;
    }
    return 0;
}