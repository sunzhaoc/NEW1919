/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-17 21:26:21
 * @LastEditTime: 2021-06-17 21:37:56
 * @FilePath: \Leetcode\AcWing\dme90.cpp
 */


# include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "12,22;0;53,11";
    vector<int> node;
    int l = 0, r = 0;
    while (r < s.size()) {
        if (r + 1 == s.size() || s[r + 1] == ';' || s[r + 1] == ',') {
            int num = 0;
            for (int i = l; i <= r; i ++) num = num * 10 + (s[i] - '0');
            if (s[r + 1] == ';') id ++;
            l = r + 2;
            r = l;
            if (num != 0) add(id, num, weight[num]);
        }
        else r + 1;
    }

    system("pause");
    return 0;
}