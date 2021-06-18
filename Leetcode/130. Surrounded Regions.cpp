/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-17 17:02:58
 * @LastEditTime: 2021-03-17 17:35:05
 * @FilePath: \Leetcode\130.Surrounded Regions.cpp
 */
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
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
TIME:     8ms    BEAT: 99.49%    O(n) = 
MEMORY: 9.9MB    BEAT: 53.58%    O(n) = 
USED TIME: 18:00
LAST EDIT TIME: 2021年3月17日17:33:16
Description: BFS 先搜与边相连的点，换成 ‘B’。扫描还有哪些是 ‘O’，这些就是被包围的点。
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // On the board
        int m = board.size(), n = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++) {
            if (board[0][i] == 'O') q.push({0, i});
            if (board[m - 1][i] == 'O') q.push({m - 1, i}); 
        }

        for (int i = 1; i < m; i ++) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n - 1] == 'O') q.push({i, n - 1});
        }

        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            board[x][y] = 'B';

            for (int i = 0; i < 4; i ++) {
                int tmpx = x + dx[i];
                int tmpy = y + dy[i];
                if (tmpx >= 0 && tmpy >= 0 && tmpx < m && tmpy < n && board[tmpx][tmpy] == 'O') q.push({tmpx, tmpy});
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
};

// @lc code=end

