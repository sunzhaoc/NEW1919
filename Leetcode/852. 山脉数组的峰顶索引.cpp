/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 14:56:35
 * @LastEditTime: 2021-06-15 08:31:53
 * @FilePath: \Leetcode\852. 山脉数组的峰顶索引.cpp
 */
/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
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
TIME:     12ms    BEAT: 72.53%    O(n) = 
MEMORY: 11.2MB    BEAT: 48.83%    O(n) = 
LAST EDIT TIME: 2021年6月15日8:31:29
Description: 二分。
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = SZ(arr) - 2; // 注意不能取边界。
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 76.16%    O(n) = logn
MEMORY: 11.1MB    BEAT: 88.95%    O(n) = nlogn
USED TIME: 03:55
LAST EDIT TIME: 2021年4月1日15:5:4
Description: 二分。
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid] < arr[mid - 1]) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 41.28%    O(n) = n
MEMORY: 11.2MB    BEAT: 69.48%    O(n) = 1
USED TIME: 01:15
LAST EDIT TIME: 2021年4月1日14:59:6
Description: 二刷。之前是python。
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1; i < arr.size() - 1; i ++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
        }
        return -1;
    }
};

// @lc code=end

