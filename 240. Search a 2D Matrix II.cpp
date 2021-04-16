/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-21 22:04:29
 * @LastEditTime: 2021-03-17 20:07:16
 * @FilePath: \Leetcode\240.Search a 2D Matrix II.cpp
 */
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:    444ms    BEAT:  8.11%    O(n) = 
MEMORY: 14.6MB    BEAT: 34.06%    O(n) = 
USED TIME: 02:38
LAST EDIT TIME: 2021年3月17日20:5:43
Description: 二刷。二分。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i ++) {
            int l = 0, r = matrix[0].size() - 1;
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:    132ms    BEAT: 68.82%    O(n) = n + m
MEMORY: 14.4MB    BEAT: 82.06%    O(n) = 1
USED TIME: 02:16
LAST EDIT TIME: 2021年3月17日20:0:41
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
TIME:   184ms    BEAT: 37.57%    O(n) = n + m
MEMORY:  15MB    BEAT:  5.74%    O(n) = 1
LAST EDIT TIME: 2020年12月21日22:33:55
Description: 
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
    vector<vector<int>> matrix = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {}};
    bool ans = sol.searchMatrix(matrix, 5);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

