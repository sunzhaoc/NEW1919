/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 19:46:01
 * @LastEditTime: 2021-04-22 19:53:02
 * @FilePath: \Leetcode\1630. Arithmetic Subarrays.cpp
 */
/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
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
TIME:     60ms    BEAT: 85.78%    O(n) = 
MEMORY: 20.4MB    BEAT: 86.02%    O(n) = 
USED TIME: 03:44
LAST EDIT TIME: 2021年4月22日19:52:51
Description: 
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        V<bool> res;
        VI tmp;
        REP(i, SZ(l)) {
            tmp.clear();
            FOR(j, l[i], r[i] + 1) {
                tmp.PB(nums[j]);
            }
            sort(ALL(tmp));
            int diff = tmp[0] - tmp[1];
            FOR(i, 1, SZ(tmp) - 1) {
                if (tmp[i] - tmp[i + 1] != diff) {
                    res.PB(false);
                    break;
                }
            }
            if (SZ(res) == i) res.PB(true);
        }
        return res;
    }
};
// @lc code=end

