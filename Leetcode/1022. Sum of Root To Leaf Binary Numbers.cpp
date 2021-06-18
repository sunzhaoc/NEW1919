/*
 * @Description:
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-13 16:01:21
 * @LastEditTime: 2021-04-13 16:09:48
 * @FilePath: \Leetcode\1022.从根到叶的二进制数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


/*
RESULT: Accept
TIME:     16ms    BEAT:  9.86%    O(n) = 
MEMORY: 16.2MB    BEAT: 84.94%    O(n) = 
USED TIME: 06:57
LAST EDIT TIME: 2021-4-13 16:9:202
Description: 
*/

class Solution {
public:
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode* node, int n) {
        if (node == nullptr) return;
        if (!node->left && !node->right) {
            sum += n + node->val;
            return;
        }
        n += node->val;
        dfs(node->left, n << 1);
        dfs(node->right, n << 1);
    }
};
// @lc code=end

