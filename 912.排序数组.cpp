/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-12 14:53:23
 * @LastEditTime: 2021-05-14 10:18:06
 * @FilePath: \Leetcode\912.排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
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
TIME:    204ms    BEAT: 5.00%    O(n) = 
MEMORY: 70.4MB    BEAT: 5.07%    O(n) = 
LAST EDIT TIME: 归并排序。
Description: 
*/

class Solution {
public:
    void merge_sort(VI& q, int l, int r) {
        if (l >= r) return;

        VI tmp(r - l + 1);
        int mid = r + l >> 1;
        merge_sort(q, l, mid);
        merge_sort(q, mid + 1, r);

        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r) tmp[k ++] = q[i] > q[j] ? q[j ++] : q[i ++];
        while (i <= mid) tmp[k ++] = q[i ++];
        while (j <= r) tmp[k ++] = q[j ++];

        for (i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, SZ(nums) - 1);
        return nums;
    }
};


/*
RESULT: Accept
TIME:     68ms    BEAT: 23.36%    O(n) = 
MEMORY: 27.7MB    BEAT: 24.67%    O(n) = 
USED TIME: 03:35
LAST EDIT TIME: 2021年5月12日14:57:18
Description: 快速排序
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, SZ(nums) - 1);
        return nums;
    }

    void quick_sort(VI& nums, int l, int r) {
        if (l >= r) return;

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
// @lc code=end

