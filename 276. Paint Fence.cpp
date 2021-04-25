/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-20 21:22:17
 * @LastEditTime: 2021-01-20 21:45:09
 * @FilePath: \Leetcode\276.Paint Fence.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  96.81%    O(n) = 
USED TIME: 19:22
LAST EDIT TIME: 2021年1月20日21:44:39
Description: DP。
*/

class Solution {
public:
    int numWays(int n, int k) {
        int arr[n];
        arr[0] = k;
        arr[1] = k * k;
        for (int i = 2; i < n; i ++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) * (k - 1);
        }
        return arr[n - 1];
    }
};


int main() {
    Solution sol;
    int ans = sol.numWays(3, 2);
    cout << ans << endl;
    system("pause");
    return 0;
}
