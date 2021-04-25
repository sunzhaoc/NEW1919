/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 20:55:05
 * @LastEditTime: 2021-04-19 21:11:35
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.05. 递归乘法.cpp
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
TIME:     4ms    BEAT: 10.30%    O(n) = 
MEMORY: 5.8MB    BEAT: 48.51%    O(n) = 
LAST EDIT TIME: 2021年4月19日21:9:5
Description: 不会。要是不知道这个公式，根本写不出来。
A * B
1、A is Even: (A // 2) * (B * 2) == (A >> 1) * (B << 1)
2、A is Odd:  (A // 2) * (B * 2) + B == (A >> 1) * (B << 1) + B
*/

class Solution {
public:
    int multiply(int A, int B) {
        int res = 0;
        while (A) {
            // Odd 
            if (A % 2) {
                res += B;
            }
            A >>= 1;
            B <<= 1;
        }
        return res;
    }
};