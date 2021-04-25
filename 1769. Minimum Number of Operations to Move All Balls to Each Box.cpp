/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-19 22:03:39
 * @LastEditTime: 2021-04-19 22:27:10
 * @FilePath: \Leetcode\1769. Minimum Number of Operations to Move All Balls to Each Box.cpp
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
TIME:     8ms    BEAT: 83.42%    O(n) = 
MEMORY: 9.2MB    BEAT: 24.38%    O(n) = 
LAST EDIT TIME: 2021年4月19日22:26:41
Description: 
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        VI res;
        int L = 0, R = 0, step = 0;
        if (boxes[0] == '1') L = 1;
        FOR(i, 1, SZ(boxes)) {
            if (boxes[i] == '1') {
                R ++;
                step += i;
            }
        }
        res.PB(step);
        FOR(i, 1, SZ(boxes)) {
            step = step + L - R;
            if (boxes[i] == '1') {
                L ++;
                R --;
            }
            res.PB(step);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:   172ms    BEAT: 46.71%    O(n) = n^2
MEMORY: 9.2MB    BEAT: 27.89%    O(n) = n
USED TIME: 02:35
LAST EDIT TIME: 2021年4月19日22:6:49
Description: 暴力
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        VI res;
        REP(i, SZ(boxes)) {
            int cnt = 0;
            REP(j, SZ(boxes)) {
                if (j == i) continue;
                if (boxes[j] == '1') {
                    cnt += abs(i - j);
                }
            }
            res.PB(cnt);
        }
        return res;
    }
};