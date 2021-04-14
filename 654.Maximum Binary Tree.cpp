/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
TIME:     92ms    BEAT: 87.34%    O(n) = 
MEMORY: 41.2MB    BEAT: 45.10%    O(n) = 
USED TIME: 08:31
LAST EDIT TIME: 2021年4月14日14:56:6
Description: 和106很像。
*/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return backTrack(nums, 0, SZ(nums) - 1);
    }

    TreeNode* backTrack(VI& nums, int l, int r) {
        if (l > r) return nullptr;

        int maxValue = INT_MIN, maxValueId;
        FOR(i, l, r + 1) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueId = i;
            }
        }

        TreeNode* cur = new TreeNode(maxValue);
        cur->left = backTrack(nums, l, maxValueId - 1);
        cur->right = backTrack(nums, maxValueId + 1, r);
        return cur;
    }
};
// @lc code=end

