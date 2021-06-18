/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-22 20:54:42
 * @LastEditTime: 2021-04-22 21:02:37
 * @FilePath: \Leetcode\1180. Count Substrings with Only One Distinct Letter.cpp
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  22.97%    O(n) = 
USED TIME: 05:37
LAST EDIT TIME: 2021年4月22日21:2:22
Description: 
*/

class Solution {
public:
    int countLetters(string S) {
        int l = 0, r = 0;
        int res = 0;
        while (r < SZ(S)) {
            while (r + 1 < SZ(S) && S[r + 1] == S[l]) r ++;
            res += multiJie(r - l + 1);
            l = r + 1;
            r = l;
        }
        return res;
    }
    
    int multiJie(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x;
            x --;
        }
        return sum;
    }
};