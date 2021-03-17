/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-21 21:41:14
 * @LastEditTime: 2021-03-17 19:41:25
 * @FilePath: \Leetcode\74.Search a 2D Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 84.19%    O(n) = n + m
MEMORY: 9.8MB    BEAT: 42.71%    O(n) = 1
Description: 2020年12月21日
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int row = 0, col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col --;
            else row ++;
        }
        return false;
    }
};


int main() {
    Solution sol;
    // vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
    vector<vector<int>> matrix = {};
    bool ans = sol.searchMatrix(matrix, 3);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

