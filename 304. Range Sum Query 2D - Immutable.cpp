/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-19 19:00:01
 * @LastEditTime: 2021-03-02 08:56:38
 * @FilePath: \Leetcode\304.Range Sum Query 2D - Immutable.cpp
 */
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:   24ms    BEAT: 81.69%    O(n) = 
MEMORY: 15MB    BEAT: 56.11%    O(n) = mn
USED TIME: 11:07
LAST EDIT TIME: 2021年3月2日8:56:30
Description: 二刷。
*/

class NumMatrix {
public:
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int row = matrix.size(), col = matrix[0].size();
        preSum.resize(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                preSum[i + 1][j + 1] = matrix[i][j] + preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 99.71%    O(n) = 
MEMORY: 14.9MB    BEAT: 98.39%    O(n) = mn
USED TIME: 41:17
LAST EDIT TIME: 2021年1月19日20:30:34
Description: 前缀和的思想。但要注意，初始化map的时候，行列要多加一个，避免边界报错。因为这个浪费了一点时间。
*/

// class NumMatrix {
// public:
//     vector<vector<int>> map;
//     NumMatrix(vector<vector<int>>& matrix) {
//         if (matrix.size() == 0) return;
//         map.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        
//         for (int i = 0; i < matrix.size(); i ++) {
//             for (int j = 0; j < matrix[0].size(); j ++) {
//                 map[i + 1][j + 1] = matrix[i][j] + map[i + 1][j] + map[i][j + 1] - map[i][j];
//             }
//         }
//         int C = 1;
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return map[row2 + 1][col2 + 1] - map[row1][col2 + 1] - map[row2 + 1][col1] + map[row1][col1];
//     }
// };


int main() {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},  {5, 6, 3, 2, 1},  {1, 2, 0, 1, 5},  {4, 1, 0, 1, 7},  {1, 0, 3, 0, 5}};
    // vector<vector<int>> matrix = {{-1}};
    NumMatrix sol(matrix);
    int ans = sol.sumRegion(2,1,4,3);
    // int ans = sol.sumRegion(1,1,2,2);
    // int ans = sol.sumRegion(0,0,0,0);
    // int ans = sol.sumRegion(2,2,2,2);
    cout << ans << endl;
    system("pause");
    return 0;
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

