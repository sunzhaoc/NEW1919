/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-06-03 08:53:15
 * @LastEditTime: 2021-06-03 09:21:37
 * @FilePath: \Leetcode\AcWing\802. 区间和.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 300010;
int a[N], s[N];
int n, m;
vector<pair<int, int>> adds, query;
vector<int> alls;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int idx, val;
        cin >> idx >> val;
        adds.push_back({idx, val});
        alls.push_back(idx);
    }
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(), alls.end());
    // 去重
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for (auto item: adds) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];
    
    for (auto item: query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
