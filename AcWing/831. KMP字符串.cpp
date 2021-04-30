/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 10:51:12
 * @LastEditTime: 2021-04-30 10:51:43
 * @FilePath: \Leetcode\AcWing\831. KMP字符串.cpp
 */
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    string s1, s2;
    cin >> n >> s1 >> m >> s2;
    vector<int> ne(m);
    
    for (int i = 1, j = 0; i < n; i ++) {
        while (j && s1[i] != s1[j]) j = ne[j - 1];
        if (s1[i] == s1[j]) j ++;
        ne[i] = j;
    }
    
    for (int i = 0, j = 0; i < m; i ++) {
        while (j && s2[i] != s1[j]) j = ne[j - 1];
        if (s2[i] == s1[j]) j ++;
        if (j == n) cout << i - n + 1 << " ";
    }
    
    return 0;
}