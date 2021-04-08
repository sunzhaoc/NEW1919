/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 20:51:53
 * @LastEditTime: 2021-04-08 12:02:15
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.08. 有重复字符串的排列组合.cpp
 */

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
TIME:   4ms    BEAT: 76.04%    O(n) = 
MEMORY: 7MB    BEAT: 54.73%    O(n) = 
USED TIME: 11:30
LAST EDIT TIME: 2021年4月8日12:1:21
Description: 又花了那么长时间。。。
*/

class Solution {
public:
    VS ans;
    vector<string> permutation(string S) {
        sort(ALL(S));
        string tmp = "";
        backTrack(tmp, S);
        return ans;
    }

    void backTrack(string& cur, string& unused) {
        if (LENGTH(unused) == 0) {
            ans.PB(cur);
            return;
        }

        REP(i, LENGTH(unused)) {
            if (i != 0 && unused[i] == unused[i - 1]) continue;
            cur += unused[i];
            string nextUnused = unused.substr(0, i) + unused.substr(i + 1);
            backTrack(cur, nextUnused);
            cur = cur.substr(0, LENGTH(cur) - 1);
        }
    }
}; 