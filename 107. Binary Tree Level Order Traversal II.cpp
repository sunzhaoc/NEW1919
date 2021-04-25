/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 11:03:47
 * @LastEditTime: 2021-03-25 11:10:24
 * @FilePath: \Leetcode\107.Binary Tree Level Order Traversal II.cpp
 */
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
TIME:      4ms    BEAT: 83.07%    O(n) = 
MEMORY: 13.5MB    BEAT:  5.09%    O(n) = 
USED TIME: 04:03
LAST EDIT TIME: 2021年3月25日11:10:5
Description: 二刷。
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        res.clear();
        dfs(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth == res.size()) {
            res.push_back({node->val});
        }
        else {
            res[depth].push_back(node->val);
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }    
};
// @lc code=end

