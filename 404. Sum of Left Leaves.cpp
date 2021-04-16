/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
RESULT: Accept
TIME:      8ms    BEAT: 35.52%    O(n) = 
MEMORY: 13.1MB    BEAT: 41.56%    O(n) = 
USED TIME: 04:44
LAST EDIT TIME: 2021年4月13日15:56:21
Description: 
*/

class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        if (node->left && node->left->left == nullptr && node->left->right == nullptr) sum += node->left->val;
        dfs(node->left);
        dfs(node->right);
    }
};
// @lc code=end

