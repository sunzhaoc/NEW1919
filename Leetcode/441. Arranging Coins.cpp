/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 13:37:53
 * @LastEditTime: 2021-03-31 14:24:20
 * @FilePath: \Leetcode\441.Arranging Coins.cpp
 */
/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
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
MEMORY: 5.8MB    BEAT:  81.14%    O(n) = 
USED TIME: 23:54
LAST EDIT TIME: 2021年3月31日14:3:1
Description: 二刷。之前是python。我也不知道为啥算术题要做这么久。
*/

class Solution {
public:
    typedef long long LL;
    int arrangeCoins(int n) {
        return 2 * sqrt(0.0625 + 0.5 * n) - 0.5;
    }
};

// @lc code=end

