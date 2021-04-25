/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 16:36:54
 * @LastEditTime: 2021-04-09 18:44:29
 * @FilePath: \Leetcode\351.Android Unlock Patterns.cpp
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:    20ms    BEAT: 85.59%    O(n) = 
MEMORY: 5.8MB    BEAT: 90.68%    O(n) = 
LAST EDIT TIME: 2021年4月9日18:43:17 
Description: 不会。回溯，有点意思。
*/

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        VVI skip(10, VI(10, 0));
        skip[1][3] = 2, skip[3][1] = 2;
        skip[1][7] = 4, skip[7][1] = 4;
        skip[3][9] = 6, skip[9][3] = 6;
        skip[7][9] = 8, skip[9][7] = 8;
        skip[4][6] = 5, skip[6][4] = 5, skip[2][8] = 5, skip[8][2] = 5, skip[1][9] = 5, skip[9][1] = 5, skip[3][7] = 5, skip[7][3] = 5;
        int res = 0;
        V<bool> visited(10, false);
        FOR(i, m, n + 1) {
            // 1,3,7,9 对称
            res += backTrack(1, visited, skip, i - 1) * 4;
            // 2,4,6,8 对称
            res += backTrack(2, visited, skip, i - 1) * 4;
            // 5
            res += backTrack(5, visited, skip, i - 1);
        }
        return res;
    }

    int backTrack(int cur, V<bool>& visited, VVI& skip, int remainKey) {
        if (remainKey == 0) return 1;
        int res = 0;
        visited[cur] = true;
        
        FOR(i, 1, 10) {
            // 1 下一个Key没有走过。
            // 2 当前Key到下一个Key之间没有其他Key or 有其他Key但是已经走过了。
            if (visited[i] == false && (skip[cur][i] == 0 || visited[skip[cur][i]])) res += backTrack(i, visited, skip, remainKey - 1);
        }
        visited[cur] = false;
        return res;
    }
};