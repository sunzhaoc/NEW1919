/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 14:16:22
 * @LastEditTime: 2021-07-10 15:37:07
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 32 - III. 从上到下打印二叉树 III.cpp
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


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
TIME:      8ms    BEAT: 36.85%    O(n) = 
MEMORY: 13.3MB    BEAT:  5.00%    O(n) = 
LAST EDIT TIME: 2021年7月10日15:36:11
Description: DFS
*/

class Solution {
public:
    VVI res;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (SZ(res) == depth) res.PB({});
        res[depth].PB(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        REP(i, SZ(res)) if (i & 1 == 1) reverse(ALL(res[i]));
        return res;
    }
};


/*
RESULT: Accept
TIME:      4ms    BEAT: 81.90%    O(n) = 
MEMORY: 12.1MB    BEAT: 93.96%    O(n) = 
LAST EDIT TIME: 2021年7月10日15:34:59
Description: BFS
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        VVI res;
        queue<pair<TreeNode*, int>> q;
        q.push(MP(root, 0));
        while (SZ(q)) {
            TreeNode* tmp = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (depth == SZ(res)) res.PB({});
            res[depth].PB(tmp->val);
            if (tmp->left) q.push(MP(tmp->left, depth + 1));
            if (tmp->right) q.push(MP(tmp->right, depth + 1));
        }
        REP(i, SZ(res)) if (i & 1 == 1) reverse(ALL(res[i]));
        return res;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 51.20%    O(n) = n
MEMORY: 13.9MB    BEAT:  5.02%    O(n) = n
USED TIME:
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> res;

//     void dfs(TreeNode* node, int depth){
//         if (node == nullptr) return;
//         if (res.size() == depth) res.push_back({});
//         res[depth].push_back(node->val);
//         if (node->left) dfs(node->left, depth + 1);
//         if (node->right) dfs(node->right, depth +1);
//     }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         dfs(root, 0);
//         for (int i = 0; i < res.size(); i ++) {
//             if (i % 2 == 1) {
//                 std::reverse(res[i].begin(), res[i].end()); 
//             }
//         }
//         return res;
//     }
// };
