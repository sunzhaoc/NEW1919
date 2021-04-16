/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-22 16:28:34
 * @LastEditTime: 2021-01-22 17:20:29
 * @FilePath: \Leetcode\827.Making A Large Island.cpp
 */
/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
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
TIME:    12ms    BEAT: 100.00%    O(n) = mna(mn)
MEMORY: 9.6MB    BEAT:  81.72%    O(n) = n?
USED TIME: 41:38
LAST EDIT TIME: 2021年1月22日17:17:45
Description: 并查集。第一次自己写出并查集的Hard题，Niubility！！！！！！！
*/

class Solution {
public:
    vector<int> parent;
    vector<int> islandSize;
    vector<vector<int>> anthorMap;
    int count = 0;
    void init(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    count ++;
                    parent.push_back(i * grid[0].size() + j);
                    islandSize.push_back(1);
                }
                else {
                    parent.push_back(-1);
                    islandSize.push_back(0);
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
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootY] = rootX;
            islandSize[rootX] += islandSize[rootY];
        }
    }

    
    int largestIsland(vector<vector<int>>& grid) {
        int numRow = grid.size();
        int numCol = grid[0].size();
        
        anthorMap = grid;

        init(grid);
        if (count == numCol * numRow) return numRow * numCol;

        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = 0;
                if (i - 1 >= 0 && grid[i - 1][j] == 1) islandUnion(i * numCol + j, (i - 1) * numCol + j);
                if (i + 1 < numRow && grid[i + 1][j] == 1) islandUnion(i * numCol + j, (i + 1) * numCol + j);
                if (j - 1 >= 0 && grid[i][j - 1] == 1) islandUnion(i * numCol + j, i * numCol + j - 1);
                if (j + 1 < numCol && grid[i][j + 1] == 1) islandUnion(i * numCol + j, i * numCol + j + 1);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < numRow; i ++) {
            for (int j = 0; j < numCol; j ++) {
                if (anthorMap[i][j] == 1) continue;
                int tmp = 1;
                int A = INT_MAX, B = INT_MAX, C = INT_MAX, D = INT_MAX;
                if (i - 1 >= 0 && anthorMap[i - 1][j] == 1) {
                    A = find((i - 1) * numCol + j);
                    tmp += islandSize[A];
                };
                if (i + 1 < numRow && anthorMap[i + 1][j] == 1) {
                    B = find((i + 1) * numCol + j);
                    if (B != A) tmp += islandSize[B];
                }
                if (j - 1 >= 0 && anthorMap[i][j - 1] == 1) {
                    C = find(i * numCol + j - 1);
                    if (C != A && C != B) tmp += islandSize[C];
                }
                if (j + 1 < numCol && anthorMap[i][j + 1] == 1) {
                    D = find(i * numCol + j + 1);
                    if (D != A && D != B && D != C) tmp += islandSize[D];
                }
                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    int ans = sol.largestIsland(grid);
    cout << ans << endl; 
    system("pause");
    return 0;
}


// @lc code=end

