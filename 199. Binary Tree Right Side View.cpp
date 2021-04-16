/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 16:57:33
 * @LastEditTime: 2021-01-07 17:24:06
 * @FilePath: \Leetcode\199.Binary Tree Right Side View.cpp
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
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
TIME:      4ms    BEAT: 81.87%    O(n) = 
MEMORY: 11.8MB    BEAT: 62.83%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        
        if (res.size() == depth) res.push_back(node->val);
        else res[depth] = node->val;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 40.34%    O(n) = 
MEMORY: 12.5MB    BEAT:  5.11%    O(n) = 
USED TIME: 06:16
Description: 
*/

// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<int> path;
//     void dfs(TreeNode* node, int depth) {
//         if (node == nullptr) return;
        
//         if (res.size() == depth) res.push_back({});
//         res[depth].push_back(node->val);
//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         dfs(root, 0);
//         for (int i = 0; i < res.size(); i ++) {
//             path.push_back(res[i][res[i].size() - 1]);
//         }
//         return path;
//     }
// };

// @lc code=end

