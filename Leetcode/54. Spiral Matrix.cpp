/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-15 15:52:46
 * @LastEditTime: 2021-03-15 16:56:02
 * @FilePath: \Leetcode\54.Spiral Matrix.cpp
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.7MB    BEAT:  75.69%    O(n) = 
LAST EDIT TIME: 2021年3月15日16:56:5
Description: 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
        while (1) {
            // Right
            for (int i = l; i <= r; i ++) res.emplace_back(matrix[u][i]);
            if (++ u > d) break;

            // Down
            for (int i = u; i <= d; i ++) res.emplace_back(matrix[i][r]);
            if (-- r < l) break;

            // Left
            for (int i = r; i >= l; i --) res.emplace_back(matrix[d][i]);
            if (-- d < u) break;

            // Up
            for (int i = d; i >= u; i --) res.emplace_back(matrix[i][l]);
            if (++ l > r) break;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = mn
MEMORY: 6.8MB    BEAT:  40.18%    O(n) = mn
USED TIME: 28:08
LAST EDIT TIME: 2021年3月15日16:22:1
Description: 四边界法。写的有点麻烦。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return matrix[0];
        vector<int> res;
        if (matrix[0].size() == 1) {
            for (int i = 0; i < matrix.size(); i ++) res.emplace_back(matrix[i][0]);
            return res;
        }

        int limitUp = 0, limitDown = matrix.size() - 1, limitLeft = 0, limitRight = matrix[0].size() - 1;
        string dir = "right";
        while (limitUp < limitDown && limitLeft < limitRight) {
            if (dir == "right") {
                for (int i = limitLeft; i <= limitRight; i ++) {
                    res.emplace_back(matrix[limitUp][i]);
                }
                limitUp ++;
                dir = "down";
            }
            else if (dir == "down") {
                for (int i = limitUp; i <= limitDown; i ++) {
                    res.emplace_back(matrix[i][limitRight]);
                }
                limitRight --;
                dir = "left";
            }
            else if (dir == "left") {
                for (int i = limitRight; i >= limitLeft; i --) {
                    res.emplace_back(matrix[limitDown][i]);
                }
                limitDown --;
                dir = "up";
            }
            else if (dir == "up") {
                for (int i = limitDown; i >= limitUp; i --) {
                    res.emplace_back(matrix[i][limitLeft]);
                }
                limitLeft ++;
                dir = "right";
            }
        }
        if (limitUp < limitDown) {
            if (dir == "right") {
                for (int i = limitUp; i <= limitDown; i ++) {
                    res.emplace_back(matrix[i][limitRight]);
                }
            }
            else {
                for (int i = limitDown; i >= limitUp; i --) {
                    res.emplace_back(matrix[i][limitLeft]);
                }
            }
        }

        else if (limitLeft < limitRight) {
            if (dir == "down") {
                for (int i = limitRight; i >= limitLeft; i --) {
                    res.emplace_back(matrix[limitDown][i]);
                }
            }
            else {
                for (int i = limitLeft; i <= limitRight; i ++) {
                    res.emplace_back(matrix[limitUp][i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

