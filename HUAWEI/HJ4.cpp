/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 15:31:22
 * @LastEditTime: 2021-03-25 15:31:23
 * @FilePath: \Leetcode\HUAWEI\HJ4.cpp
 */
#include <iostream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)){
        int n = s.length();
        if (s.length() == 8) cout << s << endl;
        else if (s.length() < 8) {
            
            for (int i = 0; i < 8 - n; i ++) {
                s += '0';
            }
            cout << s << endl;
        }
        else {
            while (s.length() > 8) {
                int len = s.length();
                string s1 = s.substr(0, 8);
                cout << s1 << endl;
                s = s.substr(8, len - 8);
            }
            
            int len = s.length();
            if (len == 8) cout << s << endl;
            else {
                for (int i = 0; i < 8 - len; i ++) {
                    s += '0';
                }
                cout << s << endl;
            }
            
        }
    }
    return 0;
}