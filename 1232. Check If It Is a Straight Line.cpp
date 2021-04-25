/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 12:56:03
 * @LastEditTime: 2021-01-18 13:26:02
 * @FilePath: \Leetcode\1232.Check If It Is a Straight Line.cpp
 */
/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
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
TIME:    12ms    BEAT: 81.49%    O(n) = n
MEMORY: 9.7MB    BEAT: 95.23%    O(n) = 1
LAST EDIT TIME: 
Description: 利用线代知识。如果二维向量a，b共线，那么它们线性相关，且有|a,b| = 0; -> x1y2 - x2y1 = 0;
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); i ++) {
            int xi = coordinates[i][0] - coordinates[0][0];
            int yi = coordinates[i][1] - coordinates[0][1];
            if (x * yi - y * xi != 0) return false;
        }
        return true;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 96.49%    O(n) = n
MEMORY: 9.9MB    BEAT: 66.35%    O(n) = 1
USED TIME: 13:57
LAST EDIT TIME: 2021年1月18日13:12:4
Description: 用斜率需考虑除数为0的情况。
*/

// class Solution {
// public:
//     bool checkStraightLine(vector<vector<int>>& coordinates) {
//         // x = ?
//         if (coordinates[0][0] == coordinates[1][0]) {
//             int a = coordinates[0][0];
//             for (int i = 0; i < coordinates.size(); i ++) {
//                 if (coordinates[i][0] != a) return false;
//             }
//             return true;
//         }
//         // y = ?
//         else if (coordinates[0][1] == coordinates[1][1]) {
//             int a = coordinates[0][1];
//             for (int i = 0; i < coordinates.size(); i ++) {
//                 if (coordinates[i][1] != a) return false;
//             }
//             return true;
//         }
//         // y = kx + b
//         else {
//             double k = ((double)coordinates[1][1] - (double)coordinates[0][1]) / ((double)coordinates[1][0] - (double)coordinates[0][0]);
//             double b = (double)coordinates[0][1] - k * (double)coordinates[0][0];
//             for (int i = 1; i < coordinates.size(); i ++) {
//                 if (k * coordinates[i][0] + b != coordinates[i][1]) return false;
//             }
//             return true;
//         }
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> A = {{2,1},{4,2},{6,3}};
    bool ans = sol.checkStraightLine(A);
    cout << ans << endl; 
    system("pause");
    return 0;
}


// @lc code=end

