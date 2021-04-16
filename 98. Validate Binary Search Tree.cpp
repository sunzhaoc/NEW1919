/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 15:38:05
 * @LastEditTime: 2021-01-07 16:53:45
 * @FilePath: \Leetcode\98.验证二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
TIME:     12ms    BEAT: 90.14%    O(n) = 
MEMORY: 21.8MB    BEAT:  8.34%    O(n) = 
USED TIME: 12:16
Description: 
*/

class Solution {
public:;
    vector<int> res;
    bool dfs(TreeNode* node) {
        if (node == nullptr) return true;
        
        bool l = dfs(node->left);
        if (res.empty() || res[res.size() - 1] < node->val) {
            res.clear();
            res.push_back(node->val);
        }

        else return false;
        bool r = dfs(node->right);
        if (l == true && r == true)      return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 39.69%    O(n) = 
MEMORY: 21.7MB    BEAT: 20.76%    O(n) = 
USED TIME: 12:16
Description: 
*/

// class Solution {
// public:;
//     vector<int> res;
//     bool dfs(TreeNode* node) {
//         if (node == nullptr) return true;
        
//         bool l = dfs(node->left);
//         if (res.empty() || res[res.size() - 1] < node->val) res.push_back(node->val);
//         else return false;
//         bool r = dfs(node->right);
//         if (l == true && r == true)      return true;
//         else return false;
//     }
//     bool isValidBST(TreeNode* root) {
//         return dfs(root);
//     }
// };
// @lc code=end

