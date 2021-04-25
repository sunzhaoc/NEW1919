/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 16:32:31
 * @LastEditTime: 2021-03-29 16:32:55
 * @FilePath: \Leetcode\HUAWEI\HJ56.cpp
 */
#include <iostream>
#include <math.h>
using namespace std;

/*
LAST EDIT TIME: 2021年3月29日16:32:50
Description: Easy。
*/

int main() {
    int x;
    while (cin >> x) {
        int res = 0;
        for (int i = 1; i <= x; i ++) {
            int sum = 1;
            for (int j = 2; j <= sqrt(i); j ++) {
                if (i % j == 0) {
                    sum += j;
                    if (i != i / j) sum += i / j;
                    if (sum > i) break;
                }
            }
            if (sum == i) res ++;
        }
        cout << res - 1 << endl;
    }
    return 0;
}