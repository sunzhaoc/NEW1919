/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-22 14:24:34
 * @LastEditTime: 2021-04-08 13:56:56
 * @FilePath: \Leetcode\200.Number of Islands.cpp
 */
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:    16ms    BEAT: 89.81%    O(n) = 
MEMORY: 9.6MB    BEAT: 51.06%    O(n) = 
USED TIME: 15:53
LAST EDIT TIME: 二刷。BFS
Description: 
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        queue<pair<int, int>> pos;
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                
                if (grid[i][j] == '1') {
                    res += 1;
                    grid[i][j] = '0';
                    pos.push({i, j});
                    while (pos.size()) {
                        int x = pos.front().first;
                        int y = pos.front().second;
                        pos.pop();
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            pos.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
                            pos.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            pos.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
                            pos.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:    20ms    BEAT: 95.60%    O(n) = 
MEMORY: 9.8MB    BEAT: 51.84%    O(n) = 
LAST EDIT TIME: 2021年1月22日15:42:46
Description: 并查集。自己写出来的。耶~~~
*/

class Solution {
public:
    vector<int> parent;
    int count;

    void init(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * grid[0].size() + j);
                    count ++;
                }
                else {
                    parent.push_back(-1);
                }
            }
        }
    }

    int find(int x) {
        int son, tmp;
        son = x;

        while (x != parent[x]) {
            x = parent[x];
        }

        while (son != x) {
            tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }

        return x;
    }

    void islandUnion(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
            count --;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int numRow = grid.size();
        int numCol = grid[0].size();

        int ans = 0;
        init(grid);
        
        for (int i = 0; i < numRow; i ++) {
            for (int j = 0; j < numCol; j ++) {
                if (grid[i][j] == '0') continue;
                grid[i][j] = '0';
                if (i - 1 >= 0 && grid[i - 1][j] == '1') islandUnion(i * numCol + j, (i - 1) * numCol + j);
                if (i + 1 < numRow && grid[i + 1][j] == '1') islandUnion(i * numCol + j, (i + 1) * numCol + j);
                if (j - 1 >= 0 && grid[i][j - 1] == '1') islandUnion(i * numCol + j, i * numCol + j - 1);
                if (j + 1 < numCol && grid[i][j + 1] == '1') islandUnion(i * numCol + j, i * numCol + j + 1);
            }
        }
        
        return count;
    }
};


/*
RESULT: Accept
TIME:    20ms    BEAT: 95.60%    O(n) = MN
MEMORY: 9.8MB    BEAT: 53.38%    O(n) = min(M, N)
LAST EDIT TIME: 2021年1月22日15:23:30
Description: BFS
*/

// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int ans = 0;
//         for (int i = 0; i < grid.size(); i ++) {
//             for (int j = 0; j < grid[0].size(); j ++) {
//                 if (grid[i][j] == '0') continue;

//                 grid[i][j] == '0';
//                 ans ++;
//                 queue<pair<int, int>> neighbours;
//                 neighbours.push({i, j});
//                 while (!neighbours.empty()) {
//                     auto it = neighbours.front();
//                     neighbours.pop();
//                     int row = it.first, col = it.second;
                    
//                     if (row - 1 >= 0 && grid[row - 1][col] == '1') {
//                         neighbours.push({row - 1, col});
//                         grid[row - 1][col] = '0';
//                     }
//                     if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
//                         neighbours.push({row + 1, col});
//                         grid[row + 1][col] = '0';
//                     }
//                     if (col - 1 >= 0 && grid[row][col - 1] == '1') {
//                         neighbours.push({row, col - 1});
//                         grid[row][col - 1] = '0';
//                     }
//                     if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') {
//                         neighbours.push({row, col + 1});
//                         grid[row][col + 1] = '0';
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:    20ms    BEAT: 95.60%    O(n) = MN
MEMORY: 9.1MB    BEAT: 99.37%    O(n) = MN
USED TIME: 19:40
LAST EDIT TIME: 2021年1月22日14:48:22
Description: DFS。本来打算是新开一个vector<vector<bool>>来记录岛屿有没有被遍历。后来发现直接在原来的grid上改就行了。
*/

// class Solution {
// public:
//     void dfs(vector<vector<char>>& choseIsland, int x, int y) {
//         choseIsland[x][y] = '0';

//         if (x - 1 >= 0 && choseIsland[x - 1][y] == '1') dfs(choseIsland, x - 1, y);
//         if (x + 1 < choseIsland.size() && choseIsland[x + 1][y] == '1') dfs(choseIsland, x + 1, y);
//         if (y - 1 >= 0 && choseIsland[x][y - 1] == '1') dfs(choseIsland, x, y - 1); 
//         if (y + 1 < choseIsland[0].size() && choseIsland[x][y + 1] == '1') dfs(choseIsland, x, y + 1);
//     }

//     int numIslands(vector<vector<char>>& grid) {

//         int ans = 0;
//         for (int i = 0; i < grid.size(); i ++) {
//             for (int j = 0; j < grid[0].size(); j ++) {
//                 if (grid[i][j] == '0') continue;
//                 dfs(grid, i, j);
//                 ans ++;
//             }
//         }

//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<vector<char>> grid = {};
    int ans = sol.numIslands(grid);
    cout << ans << endl; 
    system("pause");
    return 0;
}


// @lc code=end

