/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-14 10:08:30
 * @LastEditTime: 2021-04-14 13:50:54
 * @FilePath: \Leetcode\662.Maximum Width of Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
TIME:     12ms    BEAT: 37.29%    O(n) = 
MEMORY: 16.1MB    BEAT: 31.01%    O(n) = 
USED TIME: 很久
LAST EDIT TIME: 2021年4月14日13:49:15 
Description: 主要是要用ULL类型。不然会溢出。这个弄了很久，一开始用的LL也还是不行。
*/

class Solution {
public:
    VI res;
    ULL ans = -1;
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }

    void dfs(TreeNode* node, ULL depth, ULL path) {
        if (!node) return;
        if (depth == SZ(res)) {
            res.PB(path);
            ans = ans == -1 ? 1: ans; // 如果写成ckmax(ans, 1) 或 ans = max(ans, 1) 会报错。
        }
        else {
            ckmax(ans, path - res[depth] + 1);
        }
        dfs(node->left, depth + 1, path << 1);
        dfs(node->right, depth + 1, (path << 1) + 1);
    }
};
// @lc code=end

