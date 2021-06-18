/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-12 20:57:55
 * @LastEditTime: 2021-04-12 21:20:05
 * @FilePath: \Leetcode\26.Remove Duplicates from Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:      4ms    BEAT: 99.03%    O(n) = 
MEMORY: 13.2MB    BEAT: 81.11%    O(n) = 
USED TIME: 20:48
LAST EDIT TIME: 2021年4月12日21:19:8 
Description: 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = SZ(nums);
        if (len == 0) return 0;
        nums.PB(INT_MIN);
        len ++;
        int id = 0, r = 1;
        while (r < len) {
            while (nums[r] == nums[r - 1]) {
                r ++;
            }
            nums[id ++] = nums[r - 1];
            r ++;
        }
        return id;
    }
};

// @lc code=end

