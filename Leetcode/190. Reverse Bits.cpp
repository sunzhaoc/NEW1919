/*
 * @Description:
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-29 13:24:20
 * @LastEditTime: 2021-03-29 13:35:38
 * @FilePath: \Leetcode\190.Reverse Bits.cpp
 */
/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
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
TIME:     4ms    BEAT: 50.83%    O(n) = 1
MEMORY: 5.7MB    BEAT: 93.63%    O(n) = 1
USED TIME: 08:33
LAST EDIT TIME: 2021年3月29日13:34:56
Description: Easy。位运算。
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long res = 0;
        int i = 32;
        while (i > 0) {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

// @lc code=end

