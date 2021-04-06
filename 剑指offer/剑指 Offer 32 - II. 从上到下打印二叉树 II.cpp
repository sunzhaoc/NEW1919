/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 14:05:49
 * @LastEditTime: 2021-01-05 14:30:29
 * @FilePath: \Leetcode\剑指 Offer 32 - II. 从上到下打印二叉树 II.cpp
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
TIME:      8ms    BEAT: 49.68%    O(n) = 
MEMORY: 13.8MB    BEAT:  5.11%    O(n) = 
USED TIME: 05:55
Description: 二叉树的前序遍历。
*/

class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* node, int depth){
        if (node == nullptr) return;
        if (res.size() == depth) res.push_back({});
        res[depth].push_back(node->val);
        if (node->left) dfs(node->left, depth + 1);
        if (node->right) dfs(node->right, depth +1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
