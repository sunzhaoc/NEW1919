/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-13 21:16:17
 * @LastEditTime: 2021-04-13 21:50:07
 * @FilePath: \Leetcode\437.Path Sum III.cpp
 */
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
TIME:      8ms    BEAT: 99.86%    O(n) = 
MEMORY: 18.2MB    BEAT: 26.66%    O(n) = 
USED TIME: 29:53
LAST EDIT TIME: 2021年4月13日21:46:42
Description: 忘记前缀和要初始化map[0] = 1;r
*/

class Solution {
public:
    int cnt = 0;
    int target;
    unordered_map<int, int> map;
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        map[0] = 1;
        dfs(root, 0);
        return cnt;
    }

    void dfs(TreeNode* node, int sum) {
        if (node == nullptr) {
            return;
        }
        sum += node->val;
        if (map.find(sum - target) != map.end() && map[sum - target] != 0) {
            cnt += map[sum - target];
        }
        map[sum] ++;
        dfs(node->left, sum);
        dfs(node->right, sum);
        map[sum] --;
    }
};
// @lc code=end

