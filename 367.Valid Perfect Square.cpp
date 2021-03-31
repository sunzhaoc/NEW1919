/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 09:56:43
 * @LastEditTime: 2021-03-31 14:25:18
 * @FilePath: \Leetcode\367.Valid Perfect Square.cpp
 */
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
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

// 这题还可以用二分来做。不写了。

/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  43.26%    O(n) = 
USED TIME: 02:01
LAST EDIT TIME: 2021年3月31日10:0:58
Description: 二刷。之前是python。
*/

class Solution {
public:
    bool isPerfectSquare(int tmp) {
        long long num = tmp;
        long long i = 0;
        while (i * i <= num) {
            if (i * i == num) return true;
            i ++;
        }
        return false;
    }
};
// @lc code=end

