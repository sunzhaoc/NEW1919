/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 14:05:03
 * @LastEditTime: 2021-04-22 14:09:14
 * @FilePath: \Leetcode\1762. Buildings With an Ocean View.cpp
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
TIME:    148ms    BEAT: 67.57%    O(n) = 
MEMORY: 67.1MB    BEAT: 64.86%    O(n) = 
USED TIME: 03:41
LAST EDIT TIME: 2021年4月22日14:8:59
Description: 
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        VI res;
        res.PB(SZ(heights) - 1);
        int maxBuilt = heights.back();
        for (int i = SZ(heights) - 2; i >= 0; i --) {
            if (heights[i] > maxBuilt) {
                res.PB(i);
                ckmax(maxBuilt, heights[i]);
            }
        }
        sort(ALL(res));
        return res;
    }
};