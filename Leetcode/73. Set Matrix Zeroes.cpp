/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-21 14:58:47
 * @LastEditTime: 2021-03-21 15:28:12
 * @FilePath: \Leetcode\73.矩阵置零.cpp
 */
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
TIME:     12ms    BEAT: 94.77%    O(n) = n*m
MEMORY: 12.9MB    BEAT: 61.43%    O(n) = 1
USED TIME: 06:20
LAST EDIT TIME: 2021年3月21日15:26:57
Description: Easy
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool r0 = false, c0 = false;
        
        for (int i = 0; i < m; i ++) {
            if (matrix[i][0] == 0) {
                r0 = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                c0 = true;
                break;
            }
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = 1; i < m; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; j ++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (r0) for (int i = 0; i < m; i ++) matrix[i][0] = 0;
        if (c0) for (int j = 0; j < n; j ++) matrix[0][j] = 0;
    }
};

// @lc code=end

