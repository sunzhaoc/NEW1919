/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-12 23:04:25
 * @LastEditTime: 2021-04-12 23:15:59
 * @FilePath: \Leetcode\112.Path Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
TIME:      8ms    BEAT: 92.58%    O(n) = 
MEMORY: 20.8MB    BEAT: 27.53%    O(n) = 
USED TIME: 09:42
LAST EDIT TIME: 2021年4月12日23:15:42
Description: 
*/

class Solution {
public:
    int target;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        target = targetSum;
        return backTrack(root, 0);
    }

    bool backTrack(TreeNode* node, int sum) {
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == target) return true;
            else return false;
        }
        else if (node->left && node->right) {
            return backTrack(node->left, sum) || backTrack(node->right, sum);
        }
        else if (node->left) return backTrack(node->left, sum);
        else return backTrack(node->right, sum);
    }
};
// @lc code=end

