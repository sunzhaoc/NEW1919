/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-01 21:52:12
 * @LastEditTime: 2020-12-01 22:36:32
 * @FilePath: \Leetcode\501.Find Mode in Binary Search Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
class Solution {
public:

    vector<int> res;
    int base, count, maxCount;

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }

    void update(int x){
        if (x == base){
            count++;
        } else
        {
            count = 1;
            base = x;
        }
        if (count == maxCount){
            res.push_back(base);
        }
        if (count > maxCount){
            maxCount = count;
            res = vector<int> {base};
        }
        
    }

    void dfs(TreeNode* node){
        if (!node) return;
        dfs(node->left);
        update(node->val);
        dfs(node->right);
    }
};
// @lc code=end

