/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-06 15:51:45
 * @LastEditTime: 2021-01-06 16:09:39
 * @FilePath: \Leetcode\剑指 Offer 54. 二叉搜索树的第k大节点.cpp
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
TIME:     32ms    BEAT: 56.85%    O(n) = n
MEMORY: 23.9MB    BEAT: 76.22%    O(n) = n
Description: 中序排序的变型。优化了一下，少传递一个参数。
*/

class Solution {
public:
    int count, res = 0;
    
    void dfs(TreeNode* node) {
        if (node == nullptr) return;

        dfs(node->right);
        count --;
        if (count == 0) {
            res = node->val;
            return;
        }

        dfs(node->left);
    }

    int kthLargest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return res;
    }
};


/*
RESULT: Accept
TIME:     32ms    BEAT: 56.85%    O(n) = n
MEMORY: 24.1MB    BEAT: 49.87%    O(n) = n
USED TIME: 11:29
Description: 中序排序的变型。
*/

class Solution {
public:
    int count = 0, res = 0;
    
    void dfs(TreeNode* node, int k) {
        if (node == nullptr) return;

        dfs(node->right, k);
        count ++;
        if (count == k) {
            res = node->val;
            return;
        }

        dfs(node->left, k);
    }

    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
