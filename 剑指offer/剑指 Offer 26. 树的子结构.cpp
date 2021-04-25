/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 09:34:39
 * @LastEditTime: 2021-01-05 09:56:03
 * @FilePath: \Leetcode\剑指 Offer 26. 树的子结构.cpp
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
TIME:     68ms    BEAT: 77.46%    O(n) = 
MEMORY: 33.6MB    BEAT: 19.61%    O(n) = 
USED TIME: 15:08
Description: 
*/

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        bool res = false;
        if (A->val == B->val) res = doesAHaveB(A, B);
        if (!res) res = isSubStructure(A->left, B);
        if (!res) res = isSubStructure(A->right, B);
        return res;
    }
    
    bool doesAHaveB(TreeNode* node1, TreeNode* node2) {
        if (!node2) return true;
        if (!node1) return false;
        if (node1->val != node2->val) return false;
        return doesAHaveB(node1->left,  node2->left) && doesAHaveB(node1->right, node2->right);
    }
    
};
