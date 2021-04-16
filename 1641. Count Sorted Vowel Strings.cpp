/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-07 19:13:18
 * @LastEditTime: 2021-04-07 19:28:53
 * @FilePath: \Leetcode\1641.Count Sorted Vowel Strings.cpp
 */
/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

# define POW2(X) (1 << (X))
# define CKBIT(S,X) (((S) & POW2(X)) != 0)
const double pi = acos(-1.0);
const double eps = 1e-11;
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
TIME:     4ms    BEAT: 26.23%    O(n) = 
MEMORY: 5.8MB    BEAT: 80.40%    O(n) = 
USED TIME: 13:49
LAST EDIT TIME: 2021年4月7日19:28:15
Description: 类似于357题。前缀和的找规律问题。
*/

class Solution {
public:
    int countVowelStrings(int n) {
        VI nums = {1, 1, 1, 1, 1};
        if (n == 1) return 5;
        FOR(i, 1, n) {
            FOR (j, 1, SZ(nums)) {
                nums[j] += nums[j - 1];
            }
        }
        int cnt = 0;
        for (int num: nums) cnt += num;
        return cnt;
    }
};

// @lc code=end

