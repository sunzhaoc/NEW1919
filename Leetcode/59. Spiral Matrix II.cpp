/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 08:25:01
 * @LastEditTime: 2021-03-16 08:36:49
 * @FilePath: \Leetcode\59.Spiral Matrix II.cpp
 */
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
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
MEMORY: 6.4MB    BEAT:  83.78%    O(n) = 
USED TIME: 08:16
LAST EDIT TIME: 2021年3月16日8:36:0
Description: 与54题基本相同。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n, vector<int> (n));
        int u = 0, d = n - 1, l = 0, r = n - 1;
        int a = 1;
        while (1) {
            for (int i = l; i <= r; i ++) nums[u][i] = a ++;
            if (++ u > d) break;
            for (int i = u; i <= d; i ++) nums[i][r] = a ++;
            if (-- r < l) break;
            for (int i = r; i >= l; i --) nums[d][i] = a ++;
            if (-- d < u) break;
            for (int i = d; i >= u; i --) nums[i][l] = a ++;
            if (++ l > r) break;
        }
        return nums;
    }
};
// @lc code=end

