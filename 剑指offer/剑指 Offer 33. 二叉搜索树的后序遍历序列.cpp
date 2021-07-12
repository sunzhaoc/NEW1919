/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 14:38:14
 * @LastEditTime: 2021-07-10 15:48:10
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 33. 二叉搜索树的后序遍历序列.cpp
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
MEMORY: 6.8MB    BEAT:  48.93%    O(n) = 
LAST EDIT TIME: 2021年7月10日15:47:22
Description: 
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (SZ(postorder) < 2) return true;
        return dfs(postorder, 0, SZ(postorder) - 1);
    }

    bool dfs(VI& node, int l, int r) {
        if (l >= r) return true;
        int val = node[r];
        int idx = l;
        while (idx < r && node[idx] < val) idx ++;
        FOR(i, idx, r) if (node[i] < val) return false;
        return dfs(node, l, idx - 1) && dfs(node, idx, r - 1);
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.7MB    BEAT:  84.45%    O(n) = 
LAST EDIT TIME: 2021年6月22日16:19:33
Description: 
*/

// class Solution {
// public:
//     bool dfs(vector<int>& node, int l, int r) {
//         if (l >= r) return true;
//         int val = node[r];
//         int idx = l;
//         while (idx < r && node[idx] < val) idx ++;
//         for (int i = idx; i < r; i ++) if (node[i] < val) return false;

//         return dfs(node, l, idx - 1) && dfs(node, idx, r - 1);
//     }

//     bool verifyPostorder(vector<int>& postorder) {
//         if (postorder.size() < 2) return true;
//         return dfs(postorder, 0, postorder.size() - 1);
//     }
// };


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.1MB    BEAT:  80.61%    O(n) = 
USED TIME:
Description: 递归。
*/

// class Solution {
// public:
//     bool valid(vector<int>& node, int left, int right) {
//         if (left >= right) return true;
//         int val = node[right];

//         int temp = left;
//         while (temp < right && node[temp] < val) 
//         {
//             temp ++;
//         }

//         for (int i = temp; i < right; i ++) {
//             if(node[i] < val) return false;
//         }

//         return valid(node, left, temp - 1) && valid(node, temp, right - 1);

//     }

//     bool verifyPostorder(vector<int>& postorder) {
//         if (postorder.size() < 2) return true;
//         return valid(postorder, 0, postorder.size() - 1);
//     }
// };
