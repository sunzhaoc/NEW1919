/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-26 10:45:49
 * @LastEditTime: 2021-05-26 10:53:21
 * @FilePath: \Leetcode\52.n皇后-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
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
TIME:   4ms    BEAT: 71.57%    O(n) = 
MEMORY: 6MB    BEAT: 49.41%    O(n) = 
LAST EDIT TIME: 2021年5月26日10:53:8
Description: 
*/

class Solution {
public:
    VS m;
    int cnt = 0;
    void dfs(int row, VI& a, VI& b, VI& col) {
        if (row == SZ(col)) {
            cnt ++;
            return;
        }
        for (int i = 0; i < SZ(col); i ++) {
            if (col[i] == 0 && a[i + row] == 0 && b[SZ(col) - 1 - i + row] == 0) {
                col[i] = 1;
                a[i + row] = 1;
                b[SZ(col) - 1 - i + row] = 1;
                dfs(row + 1, a, b, col);
                col[i] = 0;
                a[i + row] = 0;
                b[SZ(col) - 1 - i + row] = 0;
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        REP(i, n) {
            string tmpS = "";
            REP(j, n) {
                tmpS += ".";
            }
            m.PB(tmpS);
        }

        VI a(2 * n - 1), b(2 * n - 1), col(n);
        dfs(0, a, b, col);
        return cnt;
    }
};
// @lc code=end

