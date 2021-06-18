/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-12 22:47:47
 * @LastEditTime: 2021-04-12 22:57:42
 * @FilePath: \Leetcode\257.Binary Tree Paths.cpp
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
TIME:      4ms    BEAT: 79.35%    O(n) = 
MEMORY: 11.9MB    BEAT: 90.70%    O(n) = 
USED TIME: 08:45
LAST EDIT TIME: 2021年4月12日22:57:25
Description: 
*/

class Solution {
public:
    VS res;
    VI path;
    vector<string> binaryTreePaths(TreeNode* root) {
        backTrack(root, path);
        return res;
    }

    void backTrack(TreeNode* node, VI& path) {
        path.PB(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.PB(numToString(path));
            return;
        }
        if (node->left) {
            backTrack(node->left, path);
            path.pop_back();
        }
        if (node->right) {
            backTrack(node->right, path);
            path.pop_back();
        }
        return;
        
    }

    string numToString(VI& nums) {
        string tmp = "";
        REP(i, SZ(nums)) {
            if (i == SZ(nums) - 1) tmp += to_string(nums[i]);
            else tmp += to_string(nums[i]) + "->";
        }
        return tmp;
    }
};
// @lc code=end

