/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-17 10:53:16
 * @LastEditTime: 2021-05-17 11:11:16
 * @FilePath: \Leetcode\AcWing\792. 高精度减法.cpp
 */

# include<bits/stdc++.h>
using namespace stc;

bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i ++) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) {
    }

    vector<int> res;
    
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    
    if (cmp(A, B)) {
        auto res = sub(A, B);
        for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    }
    else {
        auto res = sub(B, A);
        cout << '-';
        for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    }
    return 0;
}