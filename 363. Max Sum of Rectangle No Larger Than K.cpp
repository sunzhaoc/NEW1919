/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-16 14:54:01
 * @LastEditTime: 2021-04-16 15:34:34
 * @FilePath: \Leetcode\363. Max Sum of Rectangle No Larger Than K.cpp
 */
/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = n^4
MEMORY: MB    BEAT: %    O(n) = n^2
LAST EDIT TIME: 2021年4月16日15:33:12
Description: 前缀和。
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        VVI map(SZ(matrix) + 1, VI(SZ(matrix[0]) + 1, 0));
        FOR(i, 0, SZ(matrix)) 
            FOR(j, 0, SZ(matrix[0])) 
                map[i + 1][j + 1] = map[i][j + 1] + map[i + 1][j] - map[i][j] + matrix[i][j];
        int res = INT_MIN;
        REP(i, SZ(matrix)) {
            REP(j, SZ(matrix[0])) {
                FOR(x, i, SZ(matrix)) {
                    FOR(y, j, SZ(matrix[0])) {
                        int cur = map[x + 1][y + 1] + map[i][j] - map[x + 1][j] - map[i][y + 1];
                        if (cur <= k && cur > res) res = cur;
                    }
                }
            }
        }
        return res;
    }
};

// @lc code=end

