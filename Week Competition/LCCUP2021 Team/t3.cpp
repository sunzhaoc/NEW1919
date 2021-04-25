/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-09 21:33:50
 * @LastEditTime: 2021-04-10 17:58:53
 * @FilePath: \Leetcode\weekcom\LCCUP2021 Team\t3.cpp
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
using VS = vector<string>;
using VVS = vector<VS>;


class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int cnt = INT_MIN;
        REP(i, SZ(bucket)) {
            int a = (vat[i] + bucket[i] - 1) / bucket[i];
            int b = ((1 + sqrt(1 + 4 * bucket[i])) / 2 + 1);
            cnt = max(cnt ,min(a,b));

        }

        return cnt;
    }
};


int main () {
    Solution sol;
    VI bucket = {1, 3};
    VI vat = {6, 8};
    // VI bucket = {1, 1};
    // VI vat = {1, 1};
    // VI bucket = {9,0,1};
    // VI vat = {0,2,2};
    // VI bucket = {1,1,1};
    // VI vat = {1000,2000,3000};
    // VI bucket = {1,2,3};
    // VI vat = {1000,0,3000};
    auto ans = sol.storeWater(bucket, vat);
    cout << ans << endl;
    system("pause");
    return 0;
}