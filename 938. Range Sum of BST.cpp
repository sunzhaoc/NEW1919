/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 16:04:35
 * @LastEditTime: 2021-04-01 16:09:07
 * @FilePath: \Leetcode\938.Range Sum of BST.cpp
 */
/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
RESULT: Accept
TIME:    200ms    BEAT: 21.40%    O(n) = 
MEMORY: 63.1MB    BEAT: 79.94%    O(n) = 
USED TIME: 02:45
LAST EDIT TIME: 2021年4月1日16:8:44
Description: 二刷。前一次python。
*/

class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return sum;
        if (root->val > high) return rangeSumBST(root->left, low, high);
        if (root->val < low) return rangeSumBST(root->right, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// @lc code=end

