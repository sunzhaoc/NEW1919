/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-22 15:47:55
 * @LastEditTime: 2021-01-22 16:07:02
 * @FilePath: \Leetcode\463.Island Perimeter.cpp
 */
/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
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
TIME:    120ms    BEAT: 99.79%    O(n) = mn
MEMORY: 93.7MB    BEAT: 99.53%    O(n) = 1
USED TIME: 04:55
LAST EDIT TIME: 2021年1月22日16:5:50
Description: 
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 0) continue;
                
                ans += 4;
                if (i - 1 >= 0 && grid[i - 1][j] == 1) ans --;
                if (i + 1 < grid.size() && grid[i + 1][j] == 1) ans --;
                if (j - 1 >= 0 && grid[i][j - 1] == 1) ans --;
                if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) ans --;
            }
        }
        return ans;
    }
};

// @lc code=end

