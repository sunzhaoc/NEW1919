/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-14 14:16:19
 * @LastEditTime: 2021-04-14 14:44:30
 * @FilePath: \Leetcode\106.从中序与后序遍历序列构造二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
TIME:     12ms    BEAT: 97.21%    O(n) = 
MEMORY: 26.2MB    BEAT: 19.95%    O(n) = 
USED TIME: 26:28
LAST EDIT TIME: 2021年4月14日14:43:47
Description: 思路一秒就有。实现还是做了一下。
*/

class Solution {
public:
    unordered_map<int, int> mapIn;
    unordered_map<int, int> mapPost;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        REP(i, SZ(inorder)) mapIn[inorder[i]] = i;
        REP(i, SZ(postorder)) mapPost[inorder[i]] = i;
        auto ans = backTrack(inorder, postorder, 0, SZ(inorder) - 1, 0, SZ(postorder) - 1);
        return ans;
    }

    TreeNode* backTrack(VI& inorder, VI& postorder, int il, int ir, int pl, int pr) {
        if (pl > pr) return nullptr;
        TreeNode* cur = new TreeNode(postorder[pr]);
        int midId = mapIn[cur->val];
        int left = midId - il;
        int right = ir - midId;
        cur->left = backTrack(inorder, postorder, il, midId - 1, pl, pl + left - 1);
        cur->right = backTrack(inorder, postorder, midId + 1, ir, pr - right, pr - 1);
        return cur;
    }
};
// @lc code=end

