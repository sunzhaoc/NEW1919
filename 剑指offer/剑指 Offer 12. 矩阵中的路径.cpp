/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-16 15:03:59
 * @LastEditTime: 2021-07-09 10:36:49
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 12. 矩阵中的路径.cpp
 */


/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */
#include <bits/stdc++.h>
using namespace std;
# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
const int MOD = 1e9 + 7;
template<class T> inline void ckmin(T &a,T b){ a = min(a, b); }
template<class T> inline void ckmax(T &a,T b){ a = max(a, b); }
template<class T> inline T sqr(T x){ return x * x; }
# define SZ(A) ((int)A.size())
# define LENGTH(A) ((int)A.length())
# define MP make_pair
# define PB push_back
# define PPB pop_back
# define PF push_front
# define PPF pop_front
# define LB lower_bound
# define UB upper_bound
# define RREP(i, a) for (int i = (a - 1); i >= 0; --i)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i) 
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define RALL(A) A.rbegin(), A.rend()
# define complete_unique(a) a.erase(unique(begin(a),end(a)),end(a))
# define F first
# define S second
# define L left
# define R right
# define V vector 
template<class T> int CMP(T a[], const T b[], int n) { return memcmp(a, b, n * sizeof(T)); }
template<class T> void COPY(T a[], const T b[], int n) { memcpy(a, b, n * sizeof(T)); }
template<class T> void SET(T a[], int val, int n) { memset(a, val, n*sizeof(T)); }
using uint = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using VPII = vector<PII>;
using PLL = pair<LL, LL>;
using VPLL = vector<PLL>;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:    12ms    BEAT: 99.97%    O(n) = 
MEMORY: 7.4MB    BEAT: 98.15%    O(n) = 
LAST EDIT TIME: 2021年7月9日10:36:39
Description: 
*/

class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = SZ(board), m = SZ(board[0]);
        REP(i, n) {
            REP(j, m) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(V<V<char>>& board, string& word, int row, int col, int depth) {
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[depth]) return false;
        if (depth == SZ(word) - 1) return true;
        board[row][col] = ' ';
        bool ans = dfs(board, word, row + 1, col, depth + 1) || dfs(board, word, row - 1, col, depth + 1) || dfs(board, word, row, col + 1, depth + 1) || dfs(board, word, row, col - 1, depth + 1);
        board[row][col] = word[depth];
        return ans;
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 98.55%    O(n) = 
MEMORY:    8MB    BEAT: 72.49%    O(n) = 
Description: 回溯 + 剪枝
*/

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {        
//         for (int i = 0; i < board.size(); i ++) {
//             for (int j = 0; j < board[0].size(); j ++) {
//                 if (dfs(board, word, i, j, 0))   return true;
//             }
//         }
//         return false;
//     }

// private:
//     bool dfs(vector<vector<char>>& board, string & word, int row, int col, int depth) {
//         if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || board[row][col] != word[depth]) return false;
//         if (depth == word.size() - 1)   return true;
//         board[row][col] = ' ';
//         bool ans = dfs(board, word, row + 1, col, depth + 1) || dfs(board, word, row - 1, col, depth + 1) || dfs(board, word, row, col + 1, depth + 1) || dfs(board, word, row, col - 1, depth + 1);
//         board[row][col] = word[depth];
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<vector<char>> list = {{'C','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}};
    bool ans = sol.exist(list, "ABCCED");
    cout << ans << endl;
    system("pause");
    return 0;
}