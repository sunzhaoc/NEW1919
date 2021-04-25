/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-12 20:39:09
 * @LastEditTime: 2021-04-12 20:51:28
 * @FilePath: \Leetcode\13.罗马数字转整数.cpp
 */
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
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
using VS = vector<string>;
using VVS = vector<VS>;

/*
RESULT: Accept
TIME:     4ms    BEAT: 95.30%    O(n) = 
MEMORY: 5.9MB    BEAT: 68.53%    O(n) = 
USED TIME: 11:22
LAST EDIT TIME: 2021年4月12日20:51:0
Description: Easy
*/

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        FOR(i, 0, SZ(s) - 1) {
            if (getValue(s[i]) < getValue(s[i + 1])) {
                res -= getValue(s[i]);
            }
            else {
                res += getValue(s[i]);
            }
        }
        res += getValue(s.back());
        return res;
    }

    int getValue(char& ch) {
        switch (ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return -1;
    }
};

// @lc code=end

