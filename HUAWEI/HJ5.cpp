/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 14:56:53
 * @LastEditTime: 2021-03-29 14:56:54
 * @FilePath: \Leetcode\HUAWEI\HJ5.cpp
 */

# include <iostream>
# include <math.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int ans = 0;
        for (int i = s.length() - 1; i > 1; i --) {
            if (s[i] >= '0' && s[i] <= '9') ans += (s[i] - '0') * pow(16, - i + s.length() - 1);
            else if (s[i] >= 'A' && s[i] <= 'F') ans += (s[i] - 'A' + 10) * pow(16, - i + s.length() - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
