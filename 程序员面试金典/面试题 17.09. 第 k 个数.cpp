/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-16 10:47:49
 * @LastEditTime: 2021-04-16 11:11:57
 * @FilePath: \Leetcode\程序员面试金典\面试题 17.09. 第 k 个数.cpp
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


/*
RESULT: Accept
TIME:     4ms    BEAT: 36.66%    O(n) = 
MEMORY: 6.1MB    BEAT: 69.48%    O(n) =    
LAST EDIT TIME: 2021年4月16日11:10:6
Description: 这题比较重要。
*/

class Solution {
public:
    int getKthMagicNumber(int k) {
        int* nums = new int[k];
        nums[0] = 1;
        int i3 = 0;
        int i5 = 0;
        int i7 = 0;
        FOR(i, 1, k) {
            nums[i] = min(min(nums[i3] * 3, nums[i5] * 5), nums[i7] * 7);
            if (nums[i] == nums[i3] * 3) i3 ++;
            if (nums[i] == nums[i5] * 5) i5 ++;
            if (nums[i] == nums[i7] * 7) i7 ++;
        }
        return nums[k - 1];
    }
};