/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-24 09:03:52
 * @LastEditTime: 2021-03-26 10:51:39
 * @FilePath: \Leetcode\891.Sum of Subsequence Widths.cpp
 */
/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int res = 0;
        int n = A.size();
        for (int i = 2; i <= n; i ++) {
            int tmp = 1;
            for (int j = n - i + 1, k = 1; k <= i; j ++, k ++) {
                tmp = tmp * j / k;
            }
            res = tmp * (i - 1);
        }
        return res;
    }
};
// @lc code=end

