/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-23 10:11:28
 * @LastEditTime: 2021-04-23 10:57:37
 * @FilePath: \Leetcode\368. Largest Divisible Subset.cpp
 */
/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
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
TIME:    48ms    BEAT: 71.97%    O(n) = 
MEMORY: 8.6MB    BEAT: 43.50%    O(n) = 
USED TIME: 。。。
LAST EDIT TIME: 2021年4月23日10:56:3
Description: 序列DP。完全不会。
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(ALL(nums));
        int n = SZ(nums);
        VI f(n, 0);
        VI g(n, 0);

        // 遍历最右边（最大）的数
        REP(i, n) {
            int len = 1, prev = i;
            REP(j, i) {
                if (nums[i] % nums[j] == 0) {
                    if (f[j] + 1 > len) {
                        len = f[j] + 1;
                        prev = j;
                    }
                }
            }
            f[i] = len;
            g[i] = prev;
        }
        
        int idx = max_element(ALL(f)) - f.begin();
        int max = f[idx];

        VI res;

        while (SZ(res) != max) {
            res.PB(nums[idx]);
            idx = g[idx];
        }
        
        return res;
    }
};


int main() {
    Solution sol;
    VI nums = {9,18,54,90,108,180,360,540,720};
    auto ans = sol.largestDivisibleSubset(nums);
    system("pause");
    return 0;
}
// @lc code=end

