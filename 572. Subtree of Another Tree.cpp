/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-13 15:03:18
 * @LastEditTime: 2021-04-13 15:47:06
 * @FilePath: \Leetcode\572.Subtree of Another Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
TIME:     32ms    BEAT: 63.43%    O(n) = 
MEMORY: 28.5MB    BEAT: 77.23%    O(n) =  
LAST EDIT TIME: 2021年4月13日15:46:7
Description: 不会。没那么难。重新定义Easy。用两重DFS。最简单的DFS。
*/

class Solution {
public:
    bool check(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if ((s && !t) || (!s && t) || (s->val != t->val)) return false;
        return check(s->left, t->left) && check(s->right, t->right);
    }
    
    bool dfs(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }
};
// @lc code=end

