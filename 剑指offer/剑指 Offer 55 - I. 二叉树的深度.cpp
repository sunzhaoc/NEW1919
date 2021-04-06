/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-06 16:16:15
 * @LastEditTime: 2021-01-06 16:22:18
 * @FilePath: \Leetcode\剑指 Offer 55 - I. 二叉树的深度.cpp
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
RESULT: Accept
TIME:     12ms    BEAT: 80.02%    O(n) = 
MEMORY: 19.1MB    BEAT: 39.13%    O(n) = 
USED TIME: 04:13
Description: 
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};
