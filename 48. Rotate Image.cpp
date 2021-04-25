/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-15 23:19:07
 * @LastEditTime: 2021-03-15 23:22:03
 * @FilePath: \Leetcode\48.Rotate Image.cpp
 */
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
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
TIME:     0ms    BEAT: 100.00%    O(n) = n^2
MEMORY: 6.9MB    BEAT:  80.83%    O(n) = 1
LAST EDIT TIME: 2021年3月15日23:20:37
Description: 与面试题01.07相同。
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n / 2; j ++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        for (int i = 0; i < n - 1; i ++) {
            for (int j = 0; j < n - 1 - i; j ++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};

// @lc code=end

