/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-05-26 10:54:37
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.12. 八皇后.cpp
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
LAST EDIT TIME: 2021年5月26日10:41:48
Description: 
*/

class Solution {
public:
    VVS res;
    void dfs(VS& m, int row, VI& col, VI& a, VI& b) {
        if (row == SZ(m)) {
            res.PB(m);
            return;
        }
        for (int i = 0; i < SZ(m); i ++) {
            if (col[i] == 0 && a[i + row] == 0 && b[SZ(m) - 1 - i + row] == 0) {
                m[row][i] = 'Q';
                a[i + row] = 1;
                b[SZ(m) - 1 - i + row] = 1;
                col[i] = 1;
                dfs(m, row + 1, col, a, b);
                m[row][i] = '.';
                a[i + row] = 0;
                b[SZ(m) - 1 - i + row] = 0;
                col[i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int len = 2 * n - 1;
        VI a(len), b(len), col(n);
        string tmpS = "";
        for (int i = 0; i < n; i ++) tmpS += ".";
        VS m(n, tmpS);
        dfs(m, 0, col, a, b);
        return res;
    }
};
// @lc code=end

