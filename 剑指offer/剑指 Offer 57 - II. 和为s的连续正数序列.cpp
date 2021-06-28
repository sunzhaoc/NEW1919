/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 19:07:19
 * @LastEditTime: 2021-06-28 16:29:58
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 57 - II. 和为s的连续正数序列.cpp
 */
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.5MB    BEAT:  71.94%    O(n) = 
LAST EDIT TIME: 2021年6月28日16:29:58
Description: 
*/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int a = 1, b = 2;
        VVI res;
        VI path;
        while (a < b) {
            int sum = (a + b) * (b - a + 1) / 2;
            if (sum == target) {
                path.clear();
                FOR(i, a, b + 1) path.PB(i);
                res.PB(path);
                a ++;
            }
            else if (sum < target) b ++;
            else a ++;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.8MB    BEAT:  79.34%    O(n) = 
USED TIME: 15:01
Description: 与下面的方法相同，只是用了等差数列的数学知识。
*/

// class Solution {
// public:
//     vector<vector<int>> findContinuousSequence(int target) {
//         int l = 1;
//         int r = 2;
//         vector<vector<int>> res;
//         vector<int> path;
//         while (l < r) {
//             int sum = (l + r) * (r - l + 1) / 2;
//             if (sum == target) {
//                 path.clear();
//                 for (int i = l; i <= r; i ++) {
//                     path.emplace_back(i);
//                 }
//                 res.emplace_back(path);
//                 l ++;
//             }
//             else if (sum < target) r ++;
//             else l ++;
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:    616ms    BEAT: 5.09%    O(n) = 
MEMORY: 96.4MB    BEAT: 5.02%    O(n) = 
USED TIME: 10:25
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> findContinuousSequence(int target) {
//         vector<vector<int>> res;

//         int begin = 1;
//         int end = target / 2 + 1;
//         while (begin < end) {
//             int sum = 0;
//             vector<int> path;
//             for (int i = begin; i <= end; i ++) {
//                 sum += i;
//                 path.push_back(i);
//                 if (sum == target) {
//                     res.push_back(path);
//                     break;
//                 } 
//                 if (sum > target)
//                 {
//                     path.clear();
//                     break;
//                 }
                
//             }
//             begin ++;
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> ans = sol.findContinuousSequence(9);
    system("pause");
    return 0;
}