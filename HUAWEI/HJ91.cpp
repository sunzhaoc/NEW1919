/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 21:29:48
 * @LastEditTime: 2021-03-31 21:30:00
 * @FilePath: \Leetcode\HUAWEI\HJ91.cpp
 */
/*
LAST EDIT TIME: 2021年3月31日21:30:2
Description: 
*/

# include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        n ++;
        m ++;
        vector<vector<int>> map(n, vector<int>(m, 1));
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        cout << map[n - 1][m - 1] << endl;
    }
    return 0;
}