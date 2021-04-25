/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 15:20:30
 * @LastEditTime: 2021-03-25 15:20:30
 * @FilePath: \Leetcode\HUAWEI\HJ3.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int x;
        unordered_set<int> map;
        vector<int> res;
        for (int i = 0; i < N; i ++) {
            cin >> x;
            if (map.find(x) == map.end()) {
                map.insert(x);
                res.push_back(x);
            }
            
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i ++) cout << res[i] << endl;
    }
    return 0;
}