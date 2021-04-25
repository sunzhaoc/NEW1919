/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-14 20:24:42
 * @LastEditTime: 2021-04-14 20:53:28
 * @FilePath: \Leetcode\demo03ACM.cpp
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


int main() {
    int n;
    while (cin >> n) {
        VI nums(n);
        REP(i, n) {
            cin >> nums[i];
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); i ++) {
            if (dp[i] == INT_MAX) {
                cout << 0 << endl;
                flag = true;
                break;
            }
            for (int k = 1; k < nums[i] + 1; k ++) {
                if (i + k > n) break;
                dp[i + k] = min(dp[i + k], dp[i] + 1);
            }
        }
        if (!flag) cout << dp.back() << endl;
    }
    system("pause");
    return 0;    
}


