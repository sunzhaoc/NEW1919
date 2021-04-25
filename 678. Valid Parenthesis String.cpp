/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 16:08:49
 * @LastEditTime: 2021-04-25 16:49:37
 * @FilePath: \Leetcode\678. Valid Parenthesis String.cpp
 */
/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
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
# define MP make_pair
# define PB push_back
# define PPB pop_back
# define PF push_front
# define PPF pop_front
# define LB lower_bound
# define UB upper_bound
# define RREP(i, a) for (int i = (a - 1); i >= 0; --i)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define RALL(A) A.rbegin(), A.rend()
# define complete_unique(a) a.erase(unique(begin(a),end(a)),end(a))
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
MEMORY: 6.1MB    BEAT:  27.41%    O(n) = 
USED TIME: ...
LAST EDIT TIME: 2021年4月25日16:49:37
Description: 不会。
https://leetcode-cn.com/problems/valid-parenthesis-string/solution/c-shuang-100-jian-dan-jie-fa-by-acceptedall/
*/

class Solution {
public:
    bool checkValidString(string s) {
        VI left, star;
        REP(i, SZ(s)) {
            if (s[i] == '(') left.PB(i);
            else if (s[i] == '*') star.PB(i);
            else {
                if (SZ(left)) left.pop_back();
                else if (SZ(star)) star.pop_back();
                else return false;
            }
        }
        if (SZ(left) > SZ(star)) return false;
        RREP(i, SZ(left)) {
            if (star.back() < left.back()) return false;
            star.PPB();
            left.PPB();
        }
        return true;
    }
};

// @lc code=end

