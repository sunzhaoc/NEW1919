/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-14 09:22:24
 * @LastEditTime: 2021-04-14 10:06:47
 * @FilePath: \Leetcode\337.House Robber III.cpp
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
using VDD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;


/*
RESULT: Accept
TIME:     16ms    BEAT: 88.94%    O(n) = n
MEMORY: 21.6MB    BEAT: 88.37%    O(n) = n
LAST EDIT TIME: 2021年4月14日10:5:33
Description: 与下面的方法相同。用的递归返回值。
虽然优化过的版本省去了哈希表的空间，但是栈空间的使用代价依旧是 O(n)O(n)，故空间复杂度不变。
*/

struct SubtreeStatus {
    int selected;
    int unselected;
};

class Solution {
public:
    
    int rob(TreeNode* root) {
        auto it = dfs(root);
        return max(it.selected, it.unselected);
    }

    SubtreeStatus dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.unselected + r.unselected;
        int unselected = max(l.selected, l.unselected) + max(r.selected, r.unselected);
        return {selected, unselected};
    }
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 19.43%    O(n) = n
MEMORY: 28.2MB    BEAT: 22.92%    O(n) = n
USED TIME: 2021年4月14日9:52:16
LAST EDIT TIME: 2021年4月14日9:49:5
Description: 树形DP。
https://leetcode-cn.com/problems/house-robber-iii/solution/da-jia-jie-she-iii-by-leetcode-solution/
*/

class Solution {
public:
    unordered_map<TreeNode*, int> tp, fp;
    
    int rob(TreeNode* root) {
        dfs(root);
        return max(fp[root], tp[root]);
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        dfs(node->right);
        tp[node] = node->val + fp[node->left] + fp[node->right]; // Choose thie Node
        fp[node] = max(fp[node->left], tp[node->left]) + max(fp[node->right], tp[node->right]);
    }
};
// @lc code=end

