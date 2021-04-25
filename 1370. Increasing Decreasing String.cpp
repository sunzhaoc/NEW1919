/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 14:19:02
 * @LastEditTime: 2021-04-22 14:30:39
 * @FilePath: \Leetcode\1370.上升下降字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
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
TIME:     4ms    BEAT: 92.32%    O(n) = 
MEMORY: 7.3MB    BEAT: 87.61%    O(n) = 
USED TIME: 14:54
LAST EDIT TIME: 2021年4月22日14:30:29
Description: 
*/

class Solution {
public:
    string sortString(string s) {
        VI nums(26, 0);
        REP(i, SZ(s)) {
            nums[s[i] - 'a'] ++;
        }
        string res = "";
        int n = SZ(s);
        while (SZ(res) < n)
        {
            int idx = 0;
            // ->
            while (idx < 26) {
                if (nums[idx] > 0) {
                    nums[idx] --;
                    res += idx + 'a';
                }
                idx ++;
            }
            
            idx = 25;
            while (idx >= 0) {
                if (nums[idx] > 0) {
                    nums[idx] --;
                    res += idx + 'a';
                }
                idx --;
            }
        }
        return res;
        
    }
};
// 
// @lc code=end

