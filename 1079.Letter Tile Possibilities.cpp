/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-07 20:35:07
 * @LastEditTime: 2021-04-07 20:50:27
 * @FilePath: \Leetcode\1079.Letter Tile Possibilities.cpp
 */
/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
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
TIME:   4ms    BEAT: 93.44%    O(n) = 
MEMORY: 6MB    BEAT: 54.43%    O(n) = 
USED TIME: 13:04
LAST EDIT TIME: 2021年4月7日20:50:11
Description: 
*/

class Solution {
public:
    int cnt = 0;
    int N;
    int numTilePossibilities(string tiles) {
        N = LENGTH(tiles);
        sort(ALL(tiles));
        backTrack(0, tiles);
        return cnt;
    }
    void backTrack(int n, string& unused) {
        if (n == N) return;
        REP(i, LENGTH(unused)) {
            if (i == 0) {
                string tmpS = unused.substr(1);
                backTrack(n + 1, tmpS);
                cnt ++;
                continue;
            }
            if (unused[i] == unused[i - 1]) continue;
            else {
                string tmpS = unused.substr(0, i) + unused.substr(i + 1);
                backTrack(n + 1, tmpS);
                cnt ++;
            }
        }
    }
};
// @lc code=end

