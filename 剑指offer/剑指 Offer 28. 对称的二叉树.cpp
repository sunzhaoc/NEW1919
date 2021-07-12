/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 10:12:59
 * @LastEditTime: 2021-07-10 14:33:55
 * @FilePath: \Leetcode\剑指offer\剑指 Offer 28. 对称的二叉树.cpp
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
TIME:     12ms    BEAT: 16.25%    O(n) = 
MEMORY: 15.7MB    BEAT: 92.59%    O(n) = 
LAST EDIT TIME: 2021年7月10日14:33:41
Description: 
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return cmp(root->left, root->right);
    }

    bool cmp(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return cmp(a->left, b->right) && cmp(a->right, b->left);
    }
};


/*
RESULT: Accept
TIME:      4ms    BEAT: 92.49%    O(n) = 
MEMORY: 16.3MB    BEAT: 58.62%    O(n) = 
USED TIME: 08:21
Description: 
*/

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr) return true;

//         return cmp(root->left, root->right);
//     }

//     bool cmp(TreeNode* node1, TreeNode* node2) {
//         if (node1 == nullptr && node2 == nullptr) return true;
//         if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) return false;
        
//         return cmp(node1->left, node2->right) && cmp(node1->right, node2->left);
//     }
// };
