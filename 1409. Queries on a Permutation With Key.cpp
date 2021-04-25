/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 12:53:02
 * @LastEditTime: 2021-04-22 13:03:06
 * @FilePath: \Leetcode\1409. Queries on a Permutation With Key.cpp
 */
/*
 * @lc app=leetcode.cn id=1409 lang=cpp
 *
 * [1409] 查询带键的排列
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
TIME:    24ms    BEAT: 38.33%    O(n) = 
MEMORY: 8.2MB    BEAT: 48.90%    O(n) = 
USED TIME: 08:00
LAST EDIT TIME: 2021年4月22日13:2:54
Description: 
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        VI P, res;
        REP(i, m) P.PB(i + 1);
        for (int query: queries) {
            int pos = -1;
            REP(i, m) {
                if (P[i] == query) {
                    pos = i;
                    break;
                }
            }
            res.PB(pos);
            P.erase(P.begin() + pos);
            P.insert(P.begin(), query);
        }
        return res;
    }
};

// @lc code=end

