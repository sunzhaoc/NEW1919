/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 16:48:41
 * @LastEditTime: 2021-03-09 18:35:31
 * @FilePath: \Leetcode\79.Word Search.cpp
 */
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
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
TIME:    148ms    BEAT: 37.46%    O(n) = 
MEMORY: 10.4MB    BEAT: 99.49%    O(n) = 
LAST EDIT TIME: 2021年3月9日18:32:19
Description: 
*/

class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& map, string& word, int i, int j, int id) {
        if (i >= row || j >= col || i < 0 || j < 0 || map[i][j] != word[id]) return false;
        if (id == word.size() - 1) return true;
        map[i][j] = ' ';
        if (dfs(map, word, i + 1, j, id + 1)
            || dfs(map, word, i, j - 1, id + 1)
            || dfs(map, word, i, j + 1, id + 1)
            || dfs(map, word, i - 1, j, id + 1)) {
            return true;
        }
        map[i][j] = word[id];
        return false;
    }
};
// @lc code=end

