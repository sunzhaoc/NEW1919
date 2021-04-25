/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 15:51:51
 * @LastEditTime: 2021-04-09 16:24:52
 * @FilePath: \Leetcode\294.Flip Game II.cpp
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
LAST EDIT TIME: 2021年4月9日16:24:18
Description: 本以为用引用可以减少空间复杂度。
*/

class Solution {
public:
    int n;
    bool canWin(string s) {
        n = SZ(s);
        return backTrack(s);
    }
    
    bool backTrack(string& s) {
        REP(i, n - 1) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                if (canWin(s) == false) return true;
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:    256ms    BEAT: 50.60%    O(n) = 
MEMORY: 45.7MB    BEAT: 33.74%    O(n) = 
LAST EDIT TIME:2021年4月9日16:4:26
Description: 不会。回溯。
*/

class Solution {
public:
    bool canWin(string s) {
        int n = SZ(s);
        REP(i, n - 1) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                if (canWin(s) == false) return true;
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return false;
    }
};