/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 16:20:00
 * @LastEditTime: 2021-04-22 16:38:09
 * @FilePath: \Leetcode\1395. Count Number of Teams.cpp
 */
/*
 * @lc app=leetcode.cn id=1395 lang=cpp
 *
 * [1395] 统计作战单位数
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
TIME:   152ms    BEAT: 32.54%    O(n) = 
MEMORY: 8.8MB    BEAT: 42.71%    O(n) = 
LAST EDIT TIME: 2021年4月22日16:37:21
Description: 枚举中间的数。牛！
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        FOR(j, 1, SZ(rating) - 1) {
            int iless = 0, imore = 0;
            int kless = 0, kmore = 0;
            REP(i, j) {
                if (rating[i] < rating[j]) iless ++;
                else if (rating[i] > rating[j]) imore ++;
            }
            FOR(k, j + 1, SZ(rating)) {
                if (rating[k] < rating[j]) kless ++;
                if (rating[k] > rating[j]) kmore ++;
            }
            cnt += iless * kmore + imore * kless;
        }
        return cnt;
    }
};

// @lc code=end

