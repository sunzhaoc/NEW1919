/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 09:29:41
 * @LastEditTime: 2021-04-22 09:41:26
 * @FilePath: \Leetcode\807.保持城市天际线.cpp
 */
/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
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
TIME:     8ms    BEAT: 78.26%    O(n) = 
MEMORY: 9.4MB    BEAT: 62.95%    O(n) = 
USED TIME: 10:39
LAST EDIT TIME: 2021年4月22日9:41:11
Description: 
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = SZ(grid), col = SZ(grid[0]);
        VI rowHigh, colHigh;
        REP(i, row) {
            rowHigh.PB(*max_element(ALL(grid[i])));
        }
        REP(j, col) {
            int tmp = -1;
            REP(i, row) {
                ckmax(tmp, grid[i][j]);
            }
            colHigh.PB(tmp);
        }
        int cnt = 0;
        REP(i, row) {
            REP(j, col) {
                cnt += min(rowHigh[j], colHigh[i]) - grid[i][j];
            }
        }
        return cnt;
    }
};
// @lc code=end

