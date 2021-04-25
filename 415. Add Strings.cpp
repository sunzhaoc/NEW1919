/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-12 20:15:15
 * @LastEditTime: 2021-04-12 20:38:20
 * @FilePath: \Leetcode\415.Add Strings.cpp
 */
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
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
TIME:     4ms    BEAT: 75.89%    O(n) = 
MEMORY: 6.7MB    BEAT: 52.64%    O(n) = 
USED TIME: 22:06
LAST EDIT TIME: 2021年4月12日20:37:49
Description: 我可能在神游。。。
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string tmpS;
        if (SZ(num1) < SZ(num2)) {
            tmpS = num2;
            num2 = num1;
            num1 = tmpS;
        } 
        int l1 = SZ(num1), l2 = SZ(num2);

        reverse(ALL(num1));
        reverse(ALL(num2));

        int a = 0;
        REP(i, max(l1, l2)) {
            if (i < l2) {
                int tmp = (num1[i] - '0') + (num2[i] - '0');
                num1[i] = tmp + a >= 10 ? (tmp + a) % 10 + '0' : tmp + a + '0';
                a = tmp + a >= 10 ? 1 : 0;
            }
            else {
                int tmp = (num1[i] - '0');
                num1[i] = tmp + a >= 10 ? (tmp + a) % 10 + '0' : tmp + a + '0';
                a = tmp + a >= 10 ? 1 : 0;
            }
        }

        reverse(ALL(num1));
        return a == 0 ? num1 : "1" + num1;
    }
};


int main() {
    Solution sol;
    auto ans = sol.addStrings("456", "77");
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

