/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-07 13:57:47
 * @LastEditTime: 2021-01-07 14:08:54
 * @FilePath: \Leetcode\剑指 Offer 68 - II. 二叉树的最近公共祖先.cpp
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 11.72%    O(n) = 
MEMORY: 14.4MB    BEAT: 42.00%    O(n) = 
USED TIME: 06:19
Description: 
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) return nullptr; 
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};