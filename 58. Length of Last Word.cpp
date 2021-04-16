/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-12 21:38:00
 * @LastEditTime: 2021-04-12 21:48:40
 * @FilePath: \Leetcode\58.Length of Last Word.cpp
 */
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.4MB    BEAT:  29.91%    O(n) = 
USED TIME: 09:35
LAST EDIT TIME: 2021年4月12日21:48:26
Description: 
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(ALL(s));
        int l = 0;
        while(l + 1 < SZ(s) && s[l] == ' ') l ++;
        if (s[l] == ' ') return 0;
        int r = l;
        while (r + 1 < SZ(s) && s[r + 1] != ' ') {
            r ++;
        }
        
        return r - l + 1;
    }
};


int main() {
    Solution sol;
    auto ans = sol.lengthOfLastWord(" ");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

