/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 15:26:53
 * @LastEditTime: 2021-04-09 15:45:31
 * @FilePath: \Leetcode\1219.Path with Maximum Gold.cpp
 */
/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
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
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define F first
# define S second
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
using VS = vector<string>;
using VVS = vector<VS>;

/*
RESULT: Accept
TIME:    60ms    BEAT: 79.55%    O(n) = 
MEMORY: 7.2MB    BEAT: 68.69%    O(n) = 
USED TIME: 15:43
LAST EDIT TIME: 2021年4月9日15:44:41
Description: 我是真没想到，真就是用两重for循环暴力求解。。。。
*/

class Solution {
public:
    int res = INT_MIN;
    int row, col;
    int getMaximumGold(vector<vector<int>>& grid) {
        row = SZ(grid), col = SZ(grid[0]);
        REP(i, SZ(grid)) {
            REP(j, SZ(grid[0])) {
                if (grid[i][j] == 0) continue;
                res = max(res, backTrack(grid, i, j));
            }
        }
        return res;
    }

    int backTrack(VVI& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0) {
            return 0;
        }
        
        int tmp = grid[x][y];
        grid[x][y] = 0;

        int maxNum = max(max(backTrack(grid, x + 1, y), backTrack(grid, x - 1, y)), max(backTrack(grid, x, y + 1), backTrack(grid, x, y - 1)));     

        grid[x][y] = tmp;
        return grid[x][y] + maxNum;
    }
};

// @lc code=end

