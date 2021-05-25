/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 13:20:18
 * @LastEditTime: 2021-05-25 13:20:18
 * @FilePath: \Leetcode\AcWing\869. 试除法求约数.cpp
 */
# include<bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i ++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n, a;
    cin >> n;
    while (n --) {
        cin >> a;
        auto res = get_divisors(a);
        for(int i = 0; i < res.size(); i ++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}