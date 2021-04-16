/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-22 15:06:25
 * @LastEditTime: 2020-12-22 15:26:00
 * @FilePath: \Leetcode\103.Binary Tree Zigzag Level Order Traversal.cpp
 */
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 25.58%    O(n) = 
MEMORY: 23.2MB    BEAT:  5.01%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        ans = dfs(root, 0, {});
        for (int i = 0; i < ans.size(); i ++) {
            if (i % 2 == 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }

    vector<vector<int>> dfs(TreeNode* node, int level, vector<vector<int>> ans) {
        if (node == nullptr) return ans;
        if (ans.size() == level)    ans.push_back({});
        ans[level].push_back(node->val);
        if (node->left) ans = dfs(node->left, level + 1, ans);
        if (node->right) ans = dfs(node->right, level + 1, ans);
        return ans;
    }
};

// @lc code=end

