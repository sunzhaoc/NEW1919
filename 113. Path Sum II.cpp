/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-13 20:38:55
 * @LastEditTime: 2021-04-13 20:58:28
 * @FilePath: \Leetcode\113.Path Sum II.cpp
 */
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
TIME:     16ms    BEAT: 40.33%    O(n) = 
MEMORY: 19.6MB    BEAT: 30.69%    O(n) = 
USED TIME: 13:17
LAST EDIT TIME: 2021年4月13日20:58:13
Description: 
*/

class Solution {
public:
    // int target;
    VVI res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // target = targetSum;
        VI tmp;
        dfs(root, tmp, targetSum);
        return res;
    }

    void dfs(TreeNode* node, VI& path, int diff) {
        if (!node) return;
        if (!node->left && !node->right) {
            if (diff - node->val == 0) {
                path.PB(node->val);
                res.PB(path);
                path.pop_back();
            }
            return;
        }

        path.PB(node->val);
        dfs(node->left, path, diff - node->val);
        dfs(node->right, path, diff - node->val);
        path.pop_back();
        
    }
};
// @lc code=end

