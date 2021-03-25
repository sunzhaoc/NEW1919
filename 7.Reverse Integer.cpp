/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-25 09:03:31
 * @LastEditTime: 2021-03-25 09:09:53
 * @FilePath: \Leetcode\7.Reverse Integer.cpp
 */
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
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
TIME:     0ms    BEAT: 100.00%    O(n) = logn
MEMORY: 5.8MB    BEAT:  64.67%    O(n) = 1
USED TIME: 04:42
LAST EDIT TIME: 2021年3月25日9:9:18
Description: 二刷。之前是python。
*/

class Solution {
public:
    int reverse(int x) {
        bool flag = (x >= 0);
        x = abs(x);
        long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        res = flag ? res : - res;
        if (res > INT_MAX || res < INT_MIN) return 0;
        return res;
    }
};

// @lc code=end

