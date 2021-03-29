/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-29 16:20:40
 * @LastEditTime: 2021-03-29 16:20:57
 * @FilePath: \Leetcode\HUAWEI\HJ106.cpp
 */

/*
LAST EDIT TIME: 2021年3月29日16:20:56
Description: Easy。
*/

# include <iostream>
# include <string>

using namespace std;
int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length() / 2; i ++) {
            swap(s[i], s[s.length() - 1 - i]);
        }
        cout << s << endl;
        
    }
    return 0;
}