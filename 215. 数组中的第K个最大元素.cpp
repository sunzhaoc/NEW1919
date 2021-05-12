/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 13:44:38
 * @LastEditTime: 2021-05-12 10:21:34
 * @FilePath: \Leetcode\215. 数组中的第K个最大元素.cpp
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
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
TIME:    16ms    BEAT: 42.74%    O(n) = 
MEMORY: 9.7MB    BEAT: 63.43%    O(n) = 
USED TIME: 03：08
LAST EDIT TIME: 2021年5月12日10:20:50
Description: 二刷。最小堆。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) return INT_MIN;

        int n = SZ(nums);
        priority_queue<int, VI, greater<int>> min_heap;

        REP(i, k) min_heap.push(nums[i]);

        FOR(i, k, n) {
            if (nums[i] >= min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 92.09%    O(n) = 
MEMORY: 9.9MB    BEAT: 33.40%    O(n) = 
LAST EDIT TIME: 2021年3月11日14:6:8
Description: 小顶堆。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) return INT_MIN;

        int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < k; i ++) {
            min_heap.push(nums[i]);
        }

        for (int i = k; i < len; i ++) {
            if (nums[i] >= min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 92.09%    O(n) = nlogn
MEMORY: 9.7MB    BEAT: 81.20%    O(n) = logn
USED TIME: 02:09
LAST EDIT TIME: 2021年3月11日13:47:50
Description: 
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int x, const int y) {return x > y;});
        return nums[k - 1];
    }
};

// @lc code=end

