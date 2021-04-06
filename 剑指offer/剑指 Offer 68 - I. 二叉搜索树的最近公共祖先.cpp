/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 13:39:35
 * @LastEditTime: 2021-01-07 13:57:10
 * @FilePath: \Leetcode\剑指 Offer 68 - I. 二叉搜索树的最近公共祖先.cpp
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
TIME:     48ms    BEAT: 24.95%    O(n) = n
MEMORY: 23.4MB    BEAT: 29.84%    O(n) = n
USED TIME: 03:47
Description: 递归。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
