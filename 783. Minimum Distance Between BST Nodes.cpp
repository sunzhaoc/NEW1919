/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-01 14:43:18
 * @LastEditTime: 2021-04-13 13:44:29
 * @FilePath: \Leetcode\783.Minimum Distance Between BST Nodes.cpp
 */
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
TIME:     8ms    BEAT: 15.03%    O(n) = 
MEMORY: 9.5MB    BEAT: 30.96%    O(n) = 
USED TIME: 03:32
LAST EDIT TIME: 2021年4月13日13:43:58
Description: 三刷。每日一题。
*/

class Solution {
public:
    VI nums;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort(ALL(nums));
        int ans = INT_MAX;
        FOR(i, 1, SZ(nums)) {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
    
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        nums.PB(node->val);
        dfs(node->right);
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 67.75%    O(n) = 
MEMORY: 9.6MB    BEAT: 28.90%    O(n) = 
USED TIME: 08:10
LAST EDIT TIME: 2021年4月1日14:54:23
Description: 二刷。前一次是python。 审题错误。花了点时间。
*/

class Solution {
public:
    vector<int> res;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for (int i = 1; i < res.size(); i ++) ans = min(ans, abs(res[i] - res[i - 1]));
        return ans;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    }
};

// @lc code=end

