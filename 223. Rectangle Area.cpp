/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-24 09:03:19
 * @LastEditTime: 2021-03-26 10:08:27
 * @FilePath: \Leetcode\223.Rectangle Area.cpp
 */
/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
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
TIME:     8ms    BEAT: 73.49%    O(n) = 
MEMORY: 5.8MB    BEAT: 60.56%    O(n) = 
LAST EDIT TIME: 2021年3月26日9:53:47
Description: 不会。。。就离谱。
线段|A, B| 和 |C, D|的重合长度 = min(B, D) - max(A, C)
当横向和纵向的重合长度均>0时，才存在重合的矩形。
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = abs(C - A) * abs(D - B) + abs(G - E) * abs(H - F);
        long long c1 = min(C, G) + 0ll - max(A, E); // int可能会溢出。比如最大-最小。但这题用int可以过。
        long long c2 = min(D, H) + 0ll - max(B, F);
        return c1 > 0 && c2 > 0 ? res - c1 * c2 : res;
    }
};

// @lc code=end