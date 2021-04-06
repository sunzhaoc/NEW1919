/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-16 15:03:59
 * @LastEditTime: 2020-12-16 16:13:07
 * @FilePath: \Leetcode\剑指 Offer 12. 矩阵中的路径.cpp
 */

#include <vector>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     20ms    BEAT: 98.55%    O(n) = 
MEMORY:    8MB    BEAT: 72.49%    O(n) = 
Description: 回溯 + 剪枝
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {        
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (dfs(board, word, i, j, 0))   return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string & word, int row, int col, int depth) {
        if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || board[row][col] != word[depth]) return false;
        if (depth == word.size() - 1)   return true;
        board[row][col] = ' ';
        bool ans = dfs(board, word, row + 1, col, depth + 1) || dfs(board, word, row - 1, col, depth + 1) || dfs(board, word, row, col + 1, depth + 1) || dfs(board, word, row, col - 1, depth + 1);
        board[row][col] = word[depth];
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> list = {{'C','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}};
    bool ans = sol.exist(list, "ABCCED");
    cout << ans << endl;
    system("pause");
    return 0;
}