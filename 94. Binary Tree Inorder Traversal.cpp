/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-01 16:16:56
 * @LastEditTime: 2020-12-01 16:48:13
 * @FilePath: \Leetcode\94.Binary Tree Inorder Traversal.cpp
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * Method 02: res写在函数外面
**/


class Solution {
public:
    vector<int> res;   

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* node){
        if (node != nullptr){
            dfs(node->left);
            res.push_back(node->val);
            dfs(node->right);
        }
    }
};


/**
 * Method 01: res写在函数里面
**/

// class Solution {
// public:

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res; 
//         res = dfs(root, res);
//         return res;
//     }

//     vector<int> dfs(TreeNode* node, vector<int> res){
//         if (node != nullptr){
//             res = dfs(node->left, res);
//             res.push_back(node->val);
//             res = dfs(node->right, res);
//         }
//         return res;
//     }
// };


// @lc code=end

