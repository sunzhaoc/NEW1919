/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-29 16:16:04
 * @LastEditTime: 2021-03-29 16:16:54
 * @FilePath: \Leetcode\HUAWEI\Hj53.cpp
 */

/*
LAST EDIT TIME: 2021年3月29日16:16:43
Description: 找规律。Easy。
*/

# include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x) {
        if (x == 1 || x == 2) cout << -1 << endl;
        else if (x % 2 == 1) cout << 2 << endl;
        else if (x % 4 == 0) cout << 3 << endl;
        else cout << 4 << endl;
    }
    return 0;
}