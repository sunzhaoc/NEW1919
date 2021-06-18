/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-13 16:25:08
 * @LastEditTime: 2021-04-13 18:11:50
 * @FilePath: \Leetcode\671.Second Minimum Node In a Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */

// @lc code=start
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
# define MP(A, B) make_pair(A, B)
# define PB(X) push_back(X)
# define FOR(i, a, b) for(int i = (a); i < (b); ++i)
# define REP(i, a) for(int i = 0; i < (a); ++i)
# define ALL(A) A.begin(), A.end()
# define F first
# define S second
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
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6.8MB    BEAT:  62.19%    O(n) = n
LAST EDIT TIME: 2021年4月13日17:7:45
Description: 这才是我想要的。
*/

class Solution {
public:
    int findSecondMinimumValue(TreeNode* node) {
        if (!node || !node->left) return -1;
        int left = node->left->val, right = node->right->val;
        
        if (node->val == left) left = findSecondMinimumValue(node->left);
        if (node->val == right) right = findSecondMinimumValue(node->right);

        if (node->val == left && node->val == right) return -1;
        int min_lr = min(left, right);
        if (node->val < min_lr) return min_lr;
        return max(left, right);        
    }
};


/*
RESULT: Accept
TIME:   4ms    BEAT: 35.82%    O(n) = n
MEMORY: 7MB    BEAT: 17.61%    O(n) = n
USED TIME: 18:58
LAST EDIT TIME: 2021年4月13日16:47:25
Description: 不想用这个笨办法。。。
*/

class Solution {
public:
    priority_queue<int, VI, greater<int>> q;
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        int n = root->val;
        while (q.size() && q.top() == n) {
            q.pop();
        }
        if (q.empty()) return -1;
        return q.top();
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        q.push(node->val);
        dfs(node->right);
    }
};

// @lc code=end

