/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-30 16:24:03
 * @LastEditTime: 2021-07-12 08:56:04
 * @FilePath: \Leetcode\Leetcode\275. H-Index II.cpp
 */
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
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
TIME:     16ms    BEAT: 89.59%    O(n) = 
MEMORY: 18.2MB    BEAT: 16.68%    O(n) = 
LAST EDIT TIME: 2021年7月12日8:55:10
Description: 麻烦。
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = SZ(citations);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // 次数、数量
            if (citations[mid] >= n - mid) r = mid;
            else l = mid + 1;
        }
        if (citations[l] >= n - l) return n - l;
        return 0;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 99.90%    O(n) = 
MEMORY: 18.2MB    BEAT:  8.93%    O(n) = 
LAST EDIT TIME: 2021年3月30日18:57:22
Description: Y总。
*/

// class Solution {
// public:
//     int hIndex(vector<int>& nums) {
//         int l = 0, r = nums.size();
//         while (l < r) {
//             int mid = l + r + 1 >> 1;
//             if (nums[nums.size() - mid] >= mid) l = mid;
//             else r = mid - 1;
//         }
//         return r;
//     }
// }; 


/*
RESULT: Accept
TIME:     24ms    BEAT: 45.48%    O(n) = 
MEMORY: 18.1MB    BEAT: 18.69%    O(n) = 
LAST EDIT TIME: 2021年3月30日16:58:43
Description: 二分。二刷。前一次是python。很难。。。不会。
*/

// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         int n = citations.size();
//         if (n == 0) return 0;
//         if (citations[n - 1] == 0) return 0;
//         int l = 0, r = n - 1;
//         while (l < r) {
//             int mid = (r - l) / 2 + l;
//             if (n - mid == citations[mid]) return n - mid; // n - mid 论文数
//             if (n - mid < citations[mid]) r = mid;
//             else l = mid + 1;
//         }
//         return n - l;
//     }
// };


// @lc code=end

