/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-13 08:54:54
 * @LastEditTime: 2021-05-13 09:56:25
 * @FilePath: \Leetcode\1269.停在原地的方案数.cpp
 */
/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
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
TIME:     16ms    BEAT: 77.12%    O(n) = 
MEMORY: 12.3MB    BEAT: 49.15%    O(n) = 
LAST EDIT TIME: 2021年5月13日9:56:10
Description: 
*/

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(steps + 1, arrLen); 

        VI dp(n, 0);
        dp[0] = 1;
        FOR(i, 1, steps + 1) {
            VI dp_next(n);
            dp_next[0] = (0ll + dp[0] + dp[1]) % MOD;
            for (int idx = 1; idx < n - 1 && dp_next[idx - 1]; idx ++) dp_next[idx] = (0ll + dp[idx - 1] + dp[idx] + dp[idx + 1]) % MOD;
            dp_next[n - 1] = (0ll + dp[n - 2] + dp[n - 1]) % MOD;
            dp = move(dp_next);
        }
        return dp[0];
    }
};

// @lc code=end

