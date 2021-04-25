/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-07 20:34:31
 * @LastEditTime: 2021-04-08 11:49:05
 * @FilePath: \Leetcode\程序员面试金典\面试题 08.07. 无重复字符串的排列组合.cpp
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-07 19:35:55
 * @LastEditTime: 2021-04-07 20:26:48
 * @FilePath: \Leetcode\temp.cpp
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
using VC = vector<char>;

/*
RESULT: Accept
TIME:     52ms    BEAT: %    O(n) = 
MEMORY: 22.6MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年4月8日11:49:5
Description: 
*/

class Solution {
public:
    VS ans;
    int N;
    vector<string> permutation(string S) {
        N = LENGTH(S);
        backTrack("", S);
        return ans;
    }

    void backTrack(string cur, string unused) {
        if (LENGTH(unused) == 0) {
            ans.PB(cur);
            return;
        }

        REP(i, LENGTH(unused)) {
            cur += unused[i];
            string nextUnused = unused.substr(0, i) + unused.substr(i + 1);
            backTrack(cur, nextUnused);
            cur = cur.substr(0, LENGTH(cur) - 1);
        }
    }
};

