/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 15:41:49
 * @LastEditTime: 2021-04-30 15:41:50
 * @FilePath: \Leetcode\AcWing\797. 差分.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, c;
int nums[100001];
int diff[100001];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> nums[i];
    for (int i = 1; i <= n; i ++) {
        if (i == 1) diff[i] = nums[i];
        else diff[i] = nums[i] - nums[i - 1];
    }
    for (int _ = 0; _ < m; _ ++) {
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        res += diff[i];
        cout << res << " ";
    }
    return 0;
}