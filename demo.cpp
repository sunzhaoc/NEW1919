/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-18 16:01:32
 * @LastEditTime: 2021-05-27 22:17:26
 * @FilePath: \Leetcode\demo.cpp
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
# define MP make_pair
# define PB push_back
# define PPB pop_back
# define PF push_front
# define PPF pop_front
# define LB lower_bound
# define UB upper_bound
# define RREP(i, a) for (int i = (a - 1); i >= 0; --i)
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



int main() {
    VI secList = {0, 57, 24, 2, 59, 39, 56, 58, 48, 43, 9, 13, 25, 31, 35, 34, 44, 55, 40, 45, 9, 49, 20, 42, 1, 4, 15, 51, 6, 59, 51, 51, 22, 41, 14, 21, 58, 19, 5, 27, 25, 13, 20, 4, 58, 4, 29, 6, 5, 31, 45, 55, 14, 30, 4, 55, 0, 28, 14, 3, 40, 8};
    VI minList = {0, 5, 38, 55, 40, 9, 40, 26, 44, 11, 47, 6, 4, 26, 28, 13, 28, 12, 19, 47, 50, 15, 2, 21, 19, 17, 20, 33, 32, 45, 35, 33, 58, 32, 3, 38, 15, 50, 22, 2, 44, 23, 49, 40, 0, 3, 9, 4, 11, 44, 16, 20, 28, 25, 38, 15, 2, 16, 12, 16, 17, 48};
    VI hourList(62, 0);
    hourList[5] = 1, hourList[9] = 1, hourList[13] = 1, hourList[14] = 1, hourList[17] = 1, hourList[18] = 1, hourList[26] = 2, hourList[27] = 1, hourList[32] = 1, hourList[35] = 1, hourList[42] = 1, hourList[43] = 1;
    int sum_hour = 0, sum_min = 0, sum_sec = 0;
    REP(i, SZ(hourList)) {
        sum_hour += hourList[i];
        sum_min += minList[i];
        sum_sec += secList[i];
    }
    LL totalSec = sum_sec + sum_min * 60 + sum_hour * 3600;
    
    int tmp_hour = 0, tmp_min = 0, tmp_sec = 0;
    REP(i, 27) {
        tmp_hour += hourList[i];
        tmp_min += minList[i];
        tmp_sec += secList[i];
    }
    LL nowSec = tmp_sec + tmp_min * 60 + tmp_hour * 3600;
    cout << 1.0 * nowSec / totalSec << endl;
    system("pause");
    return 0;
}