/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 15:06:04
 * @LastEditTime: 2021-06-22 16:33:39
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 34. 二叉树中和为某一值的路径.cpp
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
TIME:      8ms    BEAT: 86.81%    O(n) = 
MEMORY: 19.4MB    BEAT: 42.84%    O(n) = 
LAST EDIT TIME: 2021年6月22日16:33:19
Description: 
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(TreeNode* node, vector<int>& path, int a) {
        if (node == nullptr) return;
        a -= node->val;
        path.push_back(node->val);

        if (a == 0 && !node->left && !node->right) res.push_back(path); // 注意这里的定义是从根节点到叶节点为一条路径。

        if (node->left) dfs(node->left, path, a);
        if (node->right) dfs(node->right, path, a);
        
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        dfs(root, path, target);
        return res;
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 62.85%    O(n) = n
MEMORY: 19.9MB    BEAT: 52.17%    O(n) = n
USED TIME: 25:49
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> res;
    
//     void findPath(TreeNode* node, vector<int>& path, int a) {
//         if (node == nullptr) return;
        
//         a -= node->val;
//         if (a == 0 && !(node->right) && !(node->left)) {
//             path.push_back(node->val);
//             res.push_back(path);
//             path.pop_back();
//             return;
//         }

//         if (node->left) {
//             path.push_back(node->val);
//             findPath(node->left, path, a);
//             path.pop_back();
//         }

//         if (node->right) {
//             path.push_back(node->val);
//             findPath(node->right, path, a);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<int> path = {};
//         findPath(root, path, sum);
//         return res;
//     }
// };
