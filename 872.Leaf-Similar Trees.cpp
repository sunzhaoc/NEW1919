/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-13 18:38:15
 * @LastEditTime: 2021-04-13 18:52:24
 * @FilePath: \Leetcode\872.Leaf-Similar Trees.cpp
 */
/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
TIME:      4ms    BEAT: 73.75%    O(n) = 
MEMORY: 12.4MB    BEAT: 69.60%    O(n) = 
USED TIME: 11:46
LAST EDIT TIME: 2021年4月13日18:52:4
Description: 
*/

class Solution {
public:
    VI nums, nums2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfsSS(root2);
        if (SZ(nums) != SZ(nums2)) return false;
        REP(i, SZ(nums)) {
            if (nums[i] != nums2[i]) return false;
        }
        return true;
    }
    
    void dfs(TreeNode* node) {
        if (!node) return;
        if (!node->left && !node->right) nums.PB(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    void dfsSS(TreeNode* node2) {
        if (!node2) return;
        if (!node2->left && !node2->right) nums2.PB(node2->val);
        dfsSS(node2->left);
        dfsSS(node2->right);
    }
};

// @lc code=end

