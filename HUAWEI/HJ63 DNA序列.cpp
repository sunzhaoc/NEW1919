/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-08 21:32:47
 * @LastEditTime: 2021-04-08 21:34:07
 * @FilePath: \Leetcode\HUAWEI\HJ63 DNA序列.cpp
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
LAST EDIT TIME: 2021年4月8日21:34:12
*/

int main() {
    string s;
    while (getline(cin, s)) {
        int n;
        cin >> n;
        string ans = s.substr(0, n);
        int res = 0;
        REP(i, n) {
            if (s[i] == 'G' || s[i] == 'C') res ++;
        }
        int cnt = res;
        int l = 0, r = n - 1;
        while (r + 1 < LENGTH(s)) {
            if (s[l] == 'G' || s[l] == 'C') cnt --;
            l ++;
            r ++;
            if (s[r] == 'G' || s[r] == 'C') cnt ++;
            if (cnt > res) {
                res = cnt;
                ans = s.substr(l, n);
            }
        }
        cout << ans << endl;
    }
    return 0;
}