/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-21 21:41:14
 * @LastEditTime: 2021-03-30 12:28:22
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


/*
RESULT: Accept
TIME:     8ms    BEAT: 41.42%    O(n) = 
MEMORY: 9.3MB    BEAT: 48.16%    O(n) = 
USED TIME: 02:04
LAST EDIT TIME: 2021年3月30日12:28:2
Description: 三刷。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) return true;
            else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 9.4MB    BEAT:  39.17%    O(n) = 
USED TIME: 03:43
LAST EDIT TIME: 2021年3月17日19:55:27
Description: 二刷。二分。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) return true;
            else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 88.95%    O(n) = m + n
MEMORY: 9.3MB    BEAT: 55.35%    O(n) = 1
USED TIME: 03:56
LAST EDIT TIME: 2021年3月17日19:46:31
Description: 二刷。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col --;
            else row ++;
        }
        
        return false;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 84.19%    O(n) = n + m
MEMORY: 9.8MB    BEAT: 42.71%    O(n) = 1
Description: 2020年12月21日
*/

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty()) return false;
//         int row = 0, col = matrix[0].size() - 1;
        
//         while (row < matrix.size() && col >= 0) {
//             if (matrix[row][col] == target) return true;
//             else if (matrix[row][col] > target) col --;
//             else row ++;
//         }
//         return false;
//     }
// };


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

