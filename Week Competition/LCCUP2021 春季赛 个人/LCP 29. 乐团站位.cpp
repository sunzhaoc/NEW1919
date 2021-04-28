/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-26 20:24:35
 * @FilePath: \Leetcode\Week Competition\LCCUP2021 春季赛 个人\LCP 29. 乐团站位.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

typedef long long LL;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 1
MEMORY: 5.8MB    BEAT: 100.00%    O(n) = 1
LAST EDIT TIME: 2021年4月6日16:5:51
Description: 找规律。先计算是第几层上的数。
*/

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        LL n = min(min(min(xPos, yPos), num - 1 - xPos), num - 1 - yPos);
        LL U = n, D = num - 1 - n, L = n, R = num - 1 - n;
        LL cur = 0;
        
        cur += num * 1ll * num; // 不加1ll会报错。
        cur -= (num - 2 * n) * (num - 2 * n);
        cur %= 9;

        // Condition 1 UP
        if (U == xPos) {
            return (cur + yPos - L + 1) % 9 != 0 ? (cur + yPos - L + 1) % 9 : 9;
        }
        else cur += R - L + 1;
        U ++;

        // Condition 2 RIGHT
        if (R == yPos) {
            return (cur + xPos - U + 1) % 9 != 0 ? (cur + xPos - U + 1) % 9 : 9;
        }
        else cur += D - U + 1;
        R --;
        
        // Condition 3 DOWN
        if (D == xPos) {
            return (cur + R - yPos + 1) % 9 != 0 ? (cur + R - yPos + 1) % 9 : 9;
        }
        else cur += R - L + 1;
        D --;

        // Condition 4 LEFT
        return (cur + D - xPos + 1) % 9 != 0 ? (cur + D - xPos + 1) % 9 : 9;
    }
};


int main() {
    Solution sol;
    for (int i = 100000; i < 100000+100; i ++) {
        for (int j = 100000; j < 100000+100; j ++) {
            int ans = sol.orchestraLayout(10000006,i,j);
            cout << ans << endl;
        }
    }

    // cout << ans << endl;
    system("pause");
    return 0;
}
