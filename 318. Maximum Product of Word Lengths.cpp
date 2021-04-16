/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-15 20:32:31
 * @LastEditTime: 2021-04-15 21:16:52
 * @FilePath: \Leetcode\318.Maximum Product of Word Lengths.cpp
 */
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
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
TIME:     52ms    BEAT: 64.23%    O(n) = 
MEMORY: 16.4MB    BEAT: 28.33%    O(n) = 
USED TIME: .....
LAST EDIT TIME: 2021年4月15日21:16:36
Description: 
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        VI maskWord;
        for (string word: words) {
            int mask = 0;
            for (char w: word) {
                mask |= 1 << (w - 'a');
            }
            maskWord.PB(mask);
        }
        int cnt = 0;
        REP(i, SZ(words)) {
            FOR(j, i + 1, SZ(words)) {
                if ((maskWord[i] & maskWord[j]) == 0) {
                    ckmax(cnt, SZ(words[i]) * SZ(words[j]));
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

