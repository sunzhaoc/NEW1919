/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-22 16:07:09
 * @LastEditTime: 2021-01-22 16:22:21
 * @FilePath: \Leetcode\695.Max Area of Island.cpp
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
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
TIME:     20ms    BEAT: 96.10%    O(n) = 
MEMORY: 21.7MB    BEAT: 98.90%    O(n) = 
USED TIME: 10:07
LAST EDIT TIME: 2021年1月22日16:22:4
Description: DFS。
*/

class Solution {
public:
    int maxIsland = 0;          
    int tmp;
    void dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        tmp ++;

        if (x - 1 >= 0 && grid[x - 1][y] == 1) dfs(grid, x - 1, y);
        if (x + 1 < grid.size() && grid[x + 1][y] == 1) dfs(grid, x + 1, y);
        if (y - 1 >= 0 && grid[x][y - 1] == 1) dfs(grid, x, y - 1);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) dfs(grid, x, y + 1); 
        maxIsland = max(tmp, maxIsland);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 0) continue;
                tmp = 0;
                dfs(grid, i, j);
            }
        }
        return maxIsland;
    }
};

// @lc code=end

