/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-24 09:03:29
 * @LastEditTime: 2021-03-26 10:36:19
 * @FilePath: \Leetcode\829.连续整数求和.cpp
 */
/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
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
TIME:     8ms    BEAT: 17.96%    O(n) = n^(1/2)
MEMORY: 5.8MB    BEAT: 63.11%    O(n) = 1
LAST EDIT TIME: 2021年3月26日10:35:52
Description: 不会。纯数学题。
*/

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for (int b = 1; b * (b - 1) < 2 * N; b ++) {
            if (2 * N % b == 0 && (2 * N / b - b + 1) % 2 == 0) res ++;
        }
        return res;
    }
};

// @lc code=end

