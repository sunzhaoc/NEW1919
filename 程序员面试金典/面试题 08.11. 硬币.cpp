/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-08 19:41:14
 * @LastEditTime: 2021-04-08 19:42:56
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.11. 硬币.cpp
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
TIME:    104ms    BEAT: 35.78%    O(n) = 
MEMORY: 14.2MB    BEAT: 29.56%    O(n) = 
LAST EDIT TIME: 2021年4月8日19:41:48
Description: 好像是完全背包问题。
https://leetcode-cn.com/problems/coin-lcci/solution/ying-bi-by-leetcode-solution/
https://leetcode-cn.com/problems/coin-lcci/solution/cji-hu-shuang-bai-de-dong-tai-gui-hua-by-58ul/
*/

class Solution {
public:
    int waysToChange(int n) {
        VI coins = {1, 5, 10, 25};
        VI dp(n + 1);
        dp[0] = 1;
        REP(i, 4) {
            FOR(j, coins[i], n + 1) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
            }
        }
        return dp[n];
    }
};