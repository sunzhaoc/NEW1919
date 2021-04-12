/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 20:05:57
 * @LastEditTime: 2021-04-12 16:20:29
 * @FilePath: \Leetcode\179.Largest Number.cpp
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:      4ms    BEAT: 99.03%    O(n) = 
MEMORY: 10.7MB    BEAT: 80.55%    O(n) = 
LAST EDIT TIME: 2021年4月12日16:16:28
Description: 不会。建议反复看。这个排序真是有点东西的啊。
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int&x, const int& y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            } 
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });

        if (nums[0] == 0) return "0";
        string res;
        for (int &x: nums) res += to_string(x);
        return res;
    }
};


int main() {
    Solution sol;
    VI nums = {3, 30, 34, 5, 9, 31};
    auto ans = sol.largestNumber(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

