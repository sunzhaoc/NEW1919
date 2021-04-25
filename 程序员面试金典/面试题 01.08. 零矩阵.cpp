/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-15 23:22:40
 * @LastEditTime: 2021-03-15 23:29:12
 * @FilePath: \Leetcode\demo08.cpp
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
TIME:     12ms    BEAT: 91.02%    O(n) = 
MEMORY: 11.9MB    BEAT: 55.18%    O(n) = 
USED TIME: 05:45
LAST EDIT TIME: 2021年3月15日23:28:55
Description: 
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> id;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) id.push_back({i, j});
            }
        }
        for (auto &it: id) {
            for (int i = 0; i < n; i ++) {
                matrix[it[0]][i] = 0;
            }
            for (int i = 0; i < m; i ++) matrix[i][it[1]] = 0;
        }
    }
};