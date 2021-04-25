/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-07 15:27:15
 * @LastEditTime: 2021-01-07 15:30:48
 * @FilePath: \Leetcode\144.二叉树的前序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 8.7MB    BEAT:  35.92%    O(n) = 
USED TIME: 
Description: 
*/

class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        res.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end

