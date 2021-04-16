/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-02 20:33:34
 * @LastEditTime: 2021-03-02 20:44:03
 * @FilePath: \Leetcode\766.Toeplitz Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
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
using namespace std;


/*
RESULT: Accept
TIME:   24ms    BEAT: 24.03%    O(n) = nm
MEMORY: 17MB    BEAT: 63.93%    O(n) = 1
USED TIME: 05:58
LAST EDIT TIME: 2021年3月2日20:41:33
Description: 
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        for (int i = 1; i < row; i ++) {
            for (int j = 1; j < col; j ++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};

// @lc code=end

