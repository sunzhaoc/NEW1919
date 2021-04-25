/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-30 15:37:25
 * @LastEditTime: 2021-01-30 16:25:09
 * @FilePath: \Leetcode\814.Binary Tree Pruning.cpp
 */
/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
TIME:     4ms    BEAT: 70.76%    O(n) = 
MEMORY: 9.2MB    BEAT: 90.73%    O(n) = 
LAST EDIT TIME: 2021年1月30日16:24:36
Description: 后序遍历。想复杂了。
*/

class Solution {
public:
    bool dfs(TreeNode* node) {
        if (node == nullptr) return false;

        bool left = dfs(node->left);
        bool right = dfs(node->right);

        if (left == false) node->left = nullptr;
        if (right == false) node->right = nullptr;
        if (!left && !right && node->val == 0) return false;
        
        return true;
    }
    

    TreeNode* pruneTree(TreeNode* root) {
        bool tmp = dfs(root);
        if (tmp) return root;
        return nullptr;
    }
};
// @lc code=end

