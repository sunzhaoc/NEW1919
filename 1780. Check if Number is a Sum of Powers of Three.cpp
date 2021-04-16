/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-09 11:09:08
 * @LastEditTime: 2021-04-09 15:05:27
 * @FilePath: \Leetcode\1780.Check if Number is a Sum of Powers of Three.cpp
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.7MB    BEAT:  88.07%    O(n) = 
LAST EDIT TIME: 2021年4月9日15:4:19
Description: 这也太妙了。
转换成三进制。如果某一位是2，那么就是错的。
*/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};

/*
RESULT: Accept
TIME:    20ms    BEAT: 17.12%    O(n) = 
MEMORY: 6.1MB    BEAT: 13.41%    O(n) = 
USED TIME: 21:44
LAST EDIT TIME: 2021年4月9日15:1:42
Description: 回溯。
*/

class Solution {
public:
    int N = 1;
    int cnt = 0;
    bool ans = false;
    bool checkPowersOfThree(int n) {
        while (N < n) {
            N *= 3;
            cnt ++;
        }
        if (N == n) return true;
        cnt --;
        backTrack(0, n, cnt);
        return ans;
    }

    void backTrack(int cur, int target, int id) {
        if (cur > target) return;
        if (cur == target) {
            ans = true;
            return;
        }
        for (int i = id; i >= 0; i --) {
            backTrack(cur + pow(3, i), target, i - 1);
            if (ans) return;
        }
    }
};
