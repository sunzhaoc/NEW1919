/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 15:42:29
 * @LastEditTime: 2021-03-29 15:42:29
 * @FilePath: \Leetcode\HUAWEI\HJ8.cpp
 */
# include <iostream>
# include <vector>
# include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int key, val;
        map<int, int> m;
        for (int i = 0; i < n; i ++) {
            cin >> key;
            cin >> val;
            m[key] += val;
        }
        for (auto i = m.begin(); i != m.end(); i ++) {
            cout << i->first << ' ' << i->second << endl;
        }
    }
    return 0;
}