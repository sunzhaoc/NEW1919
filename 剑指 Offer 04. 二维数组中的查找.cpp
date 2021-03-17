/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-04 14:14:02
 * @LastEditTime: 2021-03-17 13:30:08
 * @FilePath: \Leetcode\剑指 Offer 04. 二维数组中的查找.cpp
 */

#include <vector>
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME:   48ms    BEAT: 93.07%    O(n) = m + n
MEMORY: 14MB    BEAT: 5.11%     O(n) = 1 
Description: 线性查找
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int min = matrix[0][0], max = matrix[matrix.size() - 1][matrix[0].size() - 1];
        if ((target > max) || (target < min))   return false;

        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row ++;
            else col --;                         
        }
        return false;
    }
};


int main(){
    Solution sol;
    bool ans = sol.findNumberIn2DArray({{}}, 20);
    cout << ans << endl;
    system("pause");
    return 0;
}