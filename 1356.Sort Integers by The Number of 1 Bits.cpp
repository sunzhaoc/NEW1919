/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-15 19:42:14
 * @LastEditTime: 2021-04-15 19:54:52
 * @FilePath: \Leetcode\1356.Sort Integers by The Number of 1 Bits.cpp
 */
/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
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
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:     8ms    BEAT: 95.67%    O(n) = 
MEMORY: 9.7MB    BEAT: 69.97%    O(n) = 
USED TIME: 10:32
LAST EDIT TIME: 2021年4月15日19:53:45
Description: 
*/

class Solution {
private:
    static int oneNum(int n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt ++;
        }
        return cnt;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(ALL(arr), [](const int x, const int y) {
            int bit_x = oneNum(x);
            int bit_y = oneNum(y);
            if (bit_x == bit_y) return x < y;
            return bit_x < bit_y;
        });
        return arr;
    }
};

// @lc code=end

