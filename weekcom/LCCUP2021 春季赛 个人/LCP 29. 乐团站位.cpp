/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-06 15:16:55
 * @FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 29. 乐团站位.cpp
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

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int n = min(min(min(xPos, yPos), num - 1 - xPos), num - 1 - yPos);
        int U = n, D = num - 1 - n, L = n, R = num - 1 - n;
        LL cur = num * num - (num - 2 * n) * (num - 2 * n);
        cur %= 9;
        int ret = 0;

        // Condition 1
        if (U == xPos) {
            
        }
        
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
