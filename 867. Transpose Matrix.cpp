/*
 * @Description: 
 * 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-11-29 21:53:23
 * @LastEditTime: 2020-11-29 22:24:21
 * @FilePath: \Leetcode\867.Transpose Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        vector<vector<int>> temp(col, vector<int>(row));
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                temp[j][i] = A[i][j];
            }
        }
        return temp;
    }
};

// @lc code=end

