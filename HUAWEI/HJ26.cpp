/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 20:57:22
 * @LastEditTime: 2021-03-24 21:23:21
 * @FilePath: \Leetcode\HUAWEI\HJ26.cpp
 */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<vector<char>> map(26);
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                map[s[i] - 'a'].push_back(s[i]);
                s[i] = 'a';
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                map[s[i] - 'A'].push_back(s[i]);
                s[i] = 'a';
            }
        }
        
        int id = 0;
        int id2 = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == 'a') {
                while (id2 == map[id].size()) {
                    id ++;
                    id2 = 0;
                }
                s[i] = map[id][id2];
                id2 ++;
            }
        }
        
        cout << s << endl;
    }
}