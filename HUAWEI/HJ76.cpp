/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 21:40:47
 * @LastEditTime: 2021-03-31 21:40:57
 * @FilePath: \Leetcode\HUAWEI\HJ76.cpp
 */

/*
LAST EDIT TIME: 2021年3月31日21:41:1
Description: 
*/

# include <iostream>
# include <string>
using namespace std;

int main() {
    int x;
    while (cin >> x) {
        string res;
        int n = x * x - x + 1;
        for (int i = 0; i < x; i ++) {
            if (i != x - 1) {
                res += to_string(n) + "+";
                n += 2;
            }
            else res += to_string(n);
        }
        cout << res << endl;
    }
    return 0;
}