/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 09:11:25
 * @LastEditTime: 2021-03-11 09:27:44
 * @FilePath: \Leetcode\102.Binary Tree Level Order Traversal.cpp
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:      4ms    BEAT: 82.12%    O(n) = 
MEMORY: 23.7MB    BEAT:  5.04%    O(n) = 
USED TIME: 09:30
LAST EDIT TIME: 2021年3月11日9:22:26
Description: 
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, {}, 0);
        return ans;
    }

    void dfs(TreeNode* node, vector<int> res, int level) {
        if (!node) return;

        if (level >= ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(node->val);
        res.push_back(node->val);
        dfs(node->left, res, level + 1);
        dfs(node->right, res, level + 1);
    }
};
// @lc code=end

