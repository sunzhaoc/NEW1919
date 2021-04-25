/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 20:44:38
 * @LastEditTime: 2021-03-31 20:45:10
 * @FilePath: \Leetcode\HUAWEI\HJ46.cpp
 */

/*
LAST EDIT TIME: 2021年3月31日20:45:61
Description: 
*/

# include <iostream>
# include <string>

using namespace std;

int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        s = s.substr(0, n);
        cout << s << endl;

    }
    return 0;
}
