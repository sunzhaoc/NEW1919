/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 21:21:21
 * @LastEditTime: 2021-03-31 21:21:33
 * @FilePath: \Leetcode\HUAWEI\HJ37.cpp
 */

/*
LAST EDIT TIME: 2021年3月31日21:21:36
Description: 
*/

# include <iostream>
# include <vector>
using namespace std;

int main() {
    int month;
    while (cin >> month) {
        vector<int> rabit(3, 0);
        rabit[1] = 1;
        for (int i = 0; i < month - 1; i ++) {
            rabit[0] += rabit[2];
            rabit[2] = rabit[1];
            rabit[1] = rabit[0];
        }
        cout << rabit[0] + rabit[1] + rabit[2] << endl;
    }
    return 0;
}