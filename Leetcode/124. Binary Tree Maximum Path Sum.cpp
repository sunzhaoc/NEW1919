/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-02 10:47:05
 * @LastEditTime: 2021-04-04 15:14:17
 * @FilePath: \Leetcode\124.Binary Tree Maximum Path Sum.cpp
 */
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

#include <math.h>
using namespace std;

/*
RESULT: Accept
TIME:     32ms    BEAT: 59.81%    O(n) = 
MEMORY: 26.8MB    BEAT: 99.23%    O(n) = 
LAST EDIT TIME: 
Description: 
1、枚举最高点。
2、对于每个最高点，计算左右最大值。
Y总。
*/

class Solution {
public:
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    // 从root向下走的最大值。
    int dfs(TreeNode* node) {
        if (!node) return 0;

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        ans = max(ans, left + right + node->val);
        return max(0, node->val + max(0, max(left, right)));
    }
};

// @lc code=end

