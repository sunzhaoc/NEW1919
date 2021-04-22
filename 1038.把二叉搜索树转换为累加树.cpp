/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-22 14:31:38
 * @LastEditTime: 2021-04-22 14:36:51
 * @FilePath: \Leetcode\1038.把二叉搜索树转换为累加树.cpp
 */
/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.8MB    BEAT:  83.01%    O(n) = 
USED TIME: 04:13
LAST EDIT TIME: 2021年4月22日14:36:41
Description: 
*/

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        auto it = dfs(root, 0);
        return root;
    }

    int dfs(TreeNode* node, int sum) {
        if (node == nullptr) return sum;
        sum = dfs(node->right, sum);
        node->val += sum;
        sum = dfs(node->left, node->val);
        return sum;
    }
};
// @lc code=end

