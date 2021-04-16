/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-15 21:19:11
 * @LastEditTime: 2021-04-15 22:00:11
 * @FilePath: \Leetcode\1239.Maximum Length of a Concatenated String with Unique Characters.cpp
 */
/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
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
TIME:     4ms    BEAT: 94.22%    O(n) = 
MEMORY: 7.8MB    BEAT: 93.98%    O(n) = 
LAST EDIT TIME: 2021年4月15日21:59:59
Description: 
*/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int m = 0;
        return dfs(arr, 0, m);
    }

    int dfs(VS& arr, int id, int m) {
        if (id == SZ(arr)) return 0;
        int t = m;
        if (isUnique(arr[id], t)) {
            int curLen = SZ(arr[id]);
            int len1 = curLen + dfs(arr, id + 1, t);
            int len2 = dfs(arr, id + 1, m);
            return max(len1, len2);
        }
        return dfs(arr, id + 1, m);
    }

    bool isUnique(string& s, int& t) {  // 这个引用要注意。
        for (char c: s) {
            if (t & (1 << (c - 'a'))) return false;
            t |= 1 << (c - 'a');
        }
        return true;
    }
};
// @lc code=end

