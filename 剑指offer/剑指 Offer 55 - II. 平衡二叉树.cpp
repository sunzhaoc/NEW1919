/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 16:24:39
 * @LastEditTime: 2021-01-06 16:37:49
 * @FilePath: \Leetcode\剑指 Offer 55 - II. 平衡二叉树.cpp
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
TIME:     24ms    BEAT: 52.82%    O(n) = 
MEMORY: 21.7MB    BEAT: 23.13%    O(n) = 
USED TIME: 07:35
Description: 
*/

class Solution {
public:
    int dfs(TreeNode* node){
        if (node == nullptr) return 0;

        int left = dfs(node->left);
        if (left == -999) return -999;
        int right = dfs(node->right);
        if (right == -999) return -999;

        if (abs(left - right) > 1) return -999;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -999;
    }
};
