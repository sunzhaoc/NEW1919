/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 09:02:53
 * @LastEditTime: 2021-03-24 18:58:43
 * @FilePath: \Leetcode\343.Integer Break.cpp
 */
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
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


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1MB    BEAT:  49.55%    O(n) = 
LAST EDIT TIME: 2021年3月24日18:58:39
Description: 优化了一下。
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int res = 1;
        if (n % 3 == 1) res *= 4, n -= 4;
        else if (n % 3 == 2) res *= 2, n -= 2;
        
        return res * pow(3, n / 3);
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  91.68%    O(n) = 
LAST EDIT TIME: 2021年3月24日18:49:27
Description: 不会。Y总的代码。
*/

// class Solution {
// public:
//     int integerBreak(int n) {
//         if (n <= 3) return n - 1;
//         int res = 1;
//         if (n % 3 == 1) res *= 4, n -= 4;
//         else if (n % 3 == 2) res *= 2, n -= 2;

//         while (n > 0) res *= 3, n -= 3;
//         return res;
//     }
// };


int main() {
    Solution sol;
    int ans = sol.integerBreak(10);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

