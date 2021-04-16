/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-13 19:16:16
 * @LastEditTime: 2021-04-13 20:38:04
 * @FilePath: \Leetcode\222.Count Complete Tree Nodes.cpp
 */
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
TIME:     36ms    BEAT: 81.56%    O(n) = 
MEMORY: 30.1MB    BEAT: 47.75%    O(n) = 
LAST EDIT TIME: 2021年4月13日20:30:28
Description: 自己写的。我真NB。二分 + 树。
*/

class Solution {
public:
    int countLevels(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth ++;
        }
        return depth;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int depth = countLevels(root);
        if (depth == 1) return 1;
        int num = (1 << (depth - 1)) - 1;
        int l = 0, r = (1 << (depth - 1)) - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (bS(root, mid, depth)) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return num + l;
    }

    bool bS(TreeNode* node, int n, int depth) {
        int tmp = 1 << (depth - 2);
        REP(i, depth - 1) {
            int num = n & tmp;
            tmp >>= 1;
            if (num == 0) node = node->left;
            else node = node->right;;
        }
        if (!node) return false;
        return true;
    }
};


/*
RESULT: Accept
TIME:   44ms    BEAT: 45.25%    O(n) = lognlogn
MEMORY: 30MB    BEAT: 95.57%    O(n) = 1
LAST EDIT TIME: 2021年4月13日19:49:1
Description: 这个处理有点东西的啊。根据完全二叉树的性质简化遍历次数。
https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/c-san-chong-fang-fa-jie-jue-wan-quan-er-cha-shu-de/
*/

class Solution {
public:
    int countLevels(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth ++;
        }
        return depth;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = countLevels(root->left);
        int right = countLevels(root->right);
        if (left == right) return countNodes(root->right) + (1 << left);
        else return countNodes(root->left) + (1 << right);
    }
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 45.25%    O(n) = n
MEMORY: 30.1MB    BEAT: 58.93%    O(n) = 1
USED TIME: 01:06
LAST EDIT TIME: 2021年4月13日19:21:53
Description: 不是最优解。没有用到完全二叉树的性质。
*/

class Solution {
public:
    int cnt = 0;
    int countNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        cnt ++;
        dfs(node->right);
    }
};
// @lc code=end

