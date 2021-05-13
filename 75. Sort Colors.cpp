/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 14:18:33
 * @LastEditTime: 2021-05-12 15:13:21
 * @FilePath: \Leetcode\75. Sort Colors.cpp
 */
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 8.1MB    BEAT:  22.43%    O(n) = 
USED TIME: 02:31
LAST EDIT TIME: 2021年5月12日15:12:57
Description: 二刷，快速排序。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, SZ(nums) - 1);
    }

    void quick_sort(VI& nums, int l, int r) {
        if (l == r) return;
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            while (nums[++ i] < x);
            while (nums[-- j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 52.86%    O(n) = 
MEMORY: 8.1MB    BEAT: 53.02%    O(n) = 
LAST EDIT TIME: 2021年3月9日14:47:19
Description: 双指针。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i ++) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2 --;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0 ++;
            }
        }
    }
};


/*
RESULT: Accept
TIME:   4ms    BEAT: 52.86%    O(n) = n
MEMORY: 8MB    BEAT: 75.58%    O(n) = 1
USED TIME: 02:46
LAST EDIT TIME: 2021年3月9日14:25:43
Description: 先统计每个颜色的个数。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int map[3] = {0, 0, 0};
        for (int num: nums) {
            map[num] ++;
        }
        for (int i = 0; i < map[0]; i ++) {
            nums[i] = 0;
        }
        for (int i = map[0]; i < map[0] + map[1]; i ++) {
            nums[i] = 1;
        }
        for (int i = map[0] + map[1]; i < nums.size(); i ++) {
            nums[i] = 2;
        }
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = nlogn
MEMORY: 8.1MB    BEAT:  54.90%    O(n) = logn
USED TIME: 00:45
LAST EDIT TIME: 2021年3月9日14:20:40
Description: 干嘛不用sort？我又不傻。
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// @lc code=end

