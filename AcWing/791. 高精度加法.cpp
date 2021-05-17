/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-17 09:46:10
 * @LastEditTime: 2021-05-17 13:32:22
 * @FilePath: \Leetcode\AcWing\791. 高精度加法.cpp
 */
# include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) return add(B, A);
    
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); i ++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t) res.push_back(t);
    return res;
}


int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    auto res = add(A, B);
    for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    return 0;
}