/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-06-02 09:51:36
 * @LastEditTime: 2021-06-02 09:51:36
 * @FilePath: \Leetcode\AcWing\AcWing 800. 数组元素的目标和.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int a;
    unordered_map<int, int> A, B;
    for (int i = 0; i < n; i ++) {
        cin >> a;
        A[a] = i;
    }
    for (int i = 0; i < m; i ++) {
        cin >> a;
        B[a] = i;
    }
    for (auto it = A.begin(); it != A.end(); it ++) {
        if (B.find(x - it->first) != B.end()) {
            cout << it->second << " " << B[x - it->first] << endl;
            return 0;
        }
    }    
    return 0;
}