/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 20:57:09
 * @LastEditTime: 2021-03-31 20:58:12
 * @FilePath: \Leetcode\HUAWEI\HJ60.cpp
 */

/*
LAST EDIT TIME: 2021年3月31日20:57:29
Description: 
*/

# include <iostream>
# include <math.h>
# include <limits.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int x;
    while (cin >> x) {
        int res = INT_MAX;
        for (int i = x / 2; i >= 1; i ++) { // 从中间遍历。当遍历到，即为最小。
            if (isPrime(i) && isPrime(x - i)) {
                res = i;
                break;
            }
        }
        cout << x - res << endl << res << endl;
        
    }
    return 0;
}