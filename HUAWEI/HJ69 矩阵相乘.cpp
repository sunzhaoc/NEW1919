/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-08 20:48:08
 * @LastEditTime: 2021-04-08 20:48:34
 * @FilePath: \Leetcode\HUAWEI\HJ69 矩阵相乘.cpp
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
LAST EDIT TIME: 2021年4月8日20:48:36
*/

int main() {
    int x, y, z;
    while(cin >> x >> y >> z){
        VVI A(x), B(y);
        REP(i, x) {
            REP(j, y){
                int tmp;
                cin >> tmp;
                A[i].PB(tmp);
            }
        }
        REP(i, y) {
            REP(j, z){
                int tmp;
                cin >> tmp;
                B[i].PB(tmp);
            }
        }
        VVI ans(x, VI(z));
        REP(i, x) {
            REP(j, z) {
                int sum = 0;
                REP(k, y) {
                    sum += A[i][k] * B[k][j];
                }
                ans[i][j] = sum;
            }
        }
        REP(i,x){
            REP(j,z){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}