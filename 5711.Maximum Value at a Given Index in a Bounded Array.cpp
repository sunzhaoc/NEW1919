/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-21 10:11:29
 * @LastEditTime: 2021-03-21 14:34:58
 * @FilePath: \Leetcode\5711.Maximum Value at a Given Index in a Bounded Array.cpp
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


class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = index;
        int r = n - index - 1;
        for (int i = maxSum; i >= 0; i --) {
            int lmax = (i - 1 + l - i + 1) * (i - 1)/ 2;
            if (i - 1 < l) lmax += (l - i + 1);
            int rmax = (i - 1 + r - i + 1) * (i-1) / 2;
            if (i - 1 < r) rmax += (r - i + 1);
            if (i + lmax + rmax <= maxSum) return i;
        }
        return -1;
        
    }
};


int main() {
    Solution sol;
    // int ans = sol.maxValue(4, 2, 6);
    int ans = sol.maxValue(6, 1, 10);
    cout << ans << endl;
    system("pause");
    return 0;
}
