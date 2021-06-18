/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-12 23:16:39
 * @LastEditTime: 2021-04-13 11:17:04
 * @FilePath: \Leetcode\680.Valid Palindrome II.cpp
 */
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
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
TIME:     48ms    BEAT: 85.32%    O(n) = 
MEMORY: 19.2MB    BEAT: 66.24%    O(n) = 
USED TIME: 20:00
LAST EDIT TIME: 2021年4月13日11:15:24
Description: 回溯。没想到需要用到回溯。本来的想法是双指针，一个从前，一个从后。但遇到 (s[l + 1] == s[r] && s[r - 1] == s[l])的情况就需要分别讨论。所以还是用了回溯。
*/

class Solution {
public:
    int flag = 0;
    bool validPalindrome(string s) {
        int len = SZ(s);
        int l = 0, r = SZ(s) - 1;
        return backTrack(s, l, r);
    }

    bool backTrack(string& s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l ++;
                r --;
                continue;
            }
            flag ++; 
            if (flag > 1) return false;
            if (s[l + 1] == s[r] && s[r - 1] == s[l]) {
                return backTrack(s, l + 1, r) || backTrack(s, l, r - 1);
            }
            if (s[l + 1] == s[r]) return backTrack(s, l + 1, r);
            else return backTrack(s, l, r - 1);
        }
        return true;
    }
};



int main() {
    Solution sol;
    auto ans = sol.validPalindrome("cupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucu");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

