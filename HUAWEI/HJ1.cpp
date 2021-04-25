/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 15:01:17
 * @LastEditTime: 2021-03-25 15:01:25
 * @FilePath: \Leetcode\HUAWEI\HJ1.cpp
 */
# include <iostream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int n = s.length();
        int r = s.length() - 1;
        while (s[r] == ' ') r --;
        int l = r;
        while (l >= 0 && s[l] != ' ') {
            l --;
        }
        cout << r - l << endl;
    }
    return 0;
}