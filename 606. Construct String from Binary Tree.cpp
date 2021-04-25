/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-13 14:30:37
 * @LastEditTime: 2021-04-13 14:48:20
 * @FilePath: \Leetcode\606.Construct String from Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
TIME:     12ms    BEAT: 98.42%    O(n) = 
MEMORY: 25.5MB    BEAT: 53.54%    O(n) = 
USED TIME: 16:25
LAST EDIT TIME: 2021年4月13日14:47:42
Description: 这题目也太不清楚了。。。。无语。
*/

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == nullptr) return "";
        else if (t->left == nullptr && t->right == nullptr) return to_string(t->val);
        else if (t->right == nullptr) return to_string(t->val) + "(" + tree2str(t->left) + ")";
        else return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};
// @lc code=end

