/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 15:24:37
 * @LastEditTime: 2021-05-18 15:23:26
 * @FilePath: \Leetcode\43. Multiply Strings.cpp
 */
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
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
# define PF push_front
# define LB lower_bound
# define UB upper_bound
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
TIME:    16ms    BEAT: 33.24%    O(n) = 
MEMORY: 7.9MB    BEAT: 37.77%    O(n) = 
USED TIME: 30:39
LAST EDIT TIME: 2021年4月25日15:56:37
Description: 
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        V<V<char>> q(SZ(num2), V<char>(SZ(num1) + SZ(num2), '0'));
        reverse(ALL(num1));
        reverse(ALL(num2));
        REP(a, SZ(num2)) {
            int z = 0;
            REP(b, SZ(num1)) {
                int x = (num2[a] - '0') * (num1[b] - '0') + z;
                z = x / 10;
                x = x % 10;
                q[a][a + b] = x + '0';
                if (b == SZ(num1) - 1 && z > 0) {
                    q[a][a + b + 1] = z + '0';
                }
            }
        }
        int a = 0;
        REP(j, SZ(q[0])) {
            int sum = 0;
            sum += a;
            REP(i, SZ(q)) {
                sum += q[i][j] - '0';
            }
            q[0][j] = (sum % 10) + '0';
            a = sum / 10;
        }
        string res = "";
        REP(i, SZ(q[0])) {
            res += q[0][i];
        }
        reverse(ALL(res));
        return res[0] == '0' ? res.substr(1) : res;
    }
};


int main () {
    Solution sol;
    auto ans = sol.multiply("2567", "48");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

