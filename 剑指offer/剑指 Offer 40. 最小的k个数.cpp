/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 18:40:37
 * @LastEditTime: 2021-07-12 16:05:21
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 40. 最小的k个数.cpp
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
TIME:     20ms    BEAT: 98.97%    O(n) = 
MEMORY: 18.6MB    BEAT: 51.93%    O(n) = 
LAST EDIT TIME: 2021年7月12日16:4:56
Description: 
*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(ALL(arr));
        VI res;
        REP(i, k) res.PB(arr[i]);
        return res;
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 55.92%    O(n) = nlogk
MEMORY: 18.9MB    BEAT: 31.42%    O(n) = k
LAST EDIT TIME: 2021年6月24日8:54:10
Description: 
*/

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> res(k, 0);
//         if (k == 0) return res;
//         priority_queue<int> q;
//         for (int i = 0; i < k; i ++) q.push(arr[i]);
//         for (int i = k; i < arr.size(); i ++) {
//             if (q.top() > arr[i]) {
//                 q.pop();
//                 q.push(arr[i]);
//             }
//         }
//         for (int i = 0; i < k; i ++) {
//             res[i] = q.top();
//             q.pop();
//         }
//         return res;        
//     }
// };


/*
RESULT: Accept
TIME:    116ms    BEAT: 32.11%    O(n) = nlogk
MEMORY: 19.4MB    BEAT: 28.42%    O(n) = k
Description: 堆。优先队列。
*/

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> ans(k, 0);
//         if (k == 0) return ans;

//         priority_queue<int> Q;
        
//         for (int i = 0; i < k; i ++) {
//             Q.push(arr[i]);
//         }

//         for (int i = k; i < arr.size(); i ++) {
//             if (Q.top() > arr[i]) {
//                 Q.pop();
//                 Q.push(arr[i]);
//             }
//         }
        
//         for (int i = 0; i < k; i ++) {
//             ans[i] = Q.top();
//             Q.pop();
//         }

//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:   72ms    BEAT: 70.31%    O(n) = nlogn
MEMORY: 19MB    BEAT: 51.31%    O(n) = logn
Description: 排序法。时间复杂度即为排序的复杂度。
*/

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> ans;
//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < k; i ++) {
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> arr = {3, 2, 1};
    vector<int> ans = sol.getLeastNumbers(arr, 2);
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
    system("pause");
    return 0;
}