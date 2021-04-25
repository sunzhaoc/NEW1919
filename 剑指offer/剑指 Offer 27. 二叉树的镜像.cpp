/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 10:02:11
 * @LastEditTime: 2021-01-05 10:06:19
 * @FilePath: \Leetcode\剑指 Offer 27. 二叉树的镜像.cpp
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 9.2MB    BEAT:  79.22%    O(n) = 
USED TIME: 02:08
Description: 
*/

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);

        root->left = right;
        root->right = left;
        
        return root;
    }
};
