/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-17 21:21:45
 * @LastEditTime: 2021-04-17 22:12:27
 * @FilePath: \Leetcode\220. Contains Duplicate III.cpp
 */
/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
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
TIME:     48ms    BEAT: 31.27%    O(n) = n
MEMORY: 17.8MB    BEAT: 11.92%    O(n) = k
LAST EDIT TIME: 2021年4月17日22:12:8
Description: 完全不会。桶排序。
*/

class Solution {
public:
    LL size;

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // k - index
        // t - value
        int n = SZ(nums);
        unordered_map<LL, LL> map;
        size = t + 1L;
        REP(i, n) {
            LL u = nums[i] * 1L;
            LL idx = getIdx(u);

            if (map.find(idx) != map.end()) return true;
            
            LL l = idx - 1, r = idx + 1;
            if (map.find(l) != map.end() && abs(u - map[l]) <= t) return true;
            if (map.find(r) != map.end() && abs(u - map[r]) <= t) return true;
            
            map.insert({idx, u});
            if (i >= k) map.erase(getIdx(nums[i - k]));
        }
        return false;
    }

    LL getIdx(LL u) {
        return u >= 0 ? u / size : (u + 1) / size - 1;
    }
};
// @lc code=end

