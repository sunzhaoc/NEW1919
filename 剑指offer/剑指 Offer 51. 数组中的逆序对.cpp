/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-14 10:32:44
 * @LastEditTime: 2021-05-14 10:33:19
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 51. 数组中的逆序对.cpp
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
TIME:     408ms    BEAT: 23.86%    O(n) = 
MEMORY: 106.1MB    BEAT: 22.11%    O(n) = 
USED TIME: 06:51
LAST EDIT TIME: 2021年5月14日10:32:54
Description: 归并排序。
*/

class Solution {
public:
    LL merge_sort(VI& nums, int l, int r) {
        if (l >= r) return 0;
        
        VI tmp(r - l + 1);
        int mid = l + r >> 1;
        LL res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);

        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                res += (mid - i + 1);
                tmp[k ++] = nums[j ++];
            }
            else tmp[k ++] = nums[i ++];
        }
        while (i <= mid) tmp[k ++] = nums[i ++];
        while (j <= r) tmp[k ++] = nums[j ++];

        for (i = l, j = 0; i <= r; i ++, j ++) nums[i] = tmp[j];
        return res;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, SZ(nums) - 1);
    }
};