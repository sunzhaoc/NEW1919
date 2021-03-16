/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-15 22:58:56
 * @LastEditTime: 2021-03-15 23:18:26
 * @FilePath: \Leetcode\demo.cpp
 */



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
TIME:     0ms    BEAT: 100.00%    O(n) = n^2
MEMORY: 6.8MB    BEAT:  88.86%    O(n) = 1
USED TIME: 16:58
LAST EDIT TIME: 2021年3月15日23:17:17
Description: 先水平翻转，再主对角线翻转。
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n / 2; j ++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }

        for (int i = 0; i < n - 1; i ++) {
            for (int j = 0; j < n - 1 - i; j ++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};