/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-08 15:22:48
 * @LastEditTime: 2021-01-08 19:32:36
 * @FilePath: \Leetcode\889.根据前序和后序遍历构造二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#include <vector>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     12ms    BEAT: 98.31%    O(n) = 
MEMORY: 25.4MB    BEAT: 51.99%    O(n) = 
Description: 
*/

class Solution {
public:
    TreeNode* dfs(vector<int>& pre, int pre_left, int pre_right, vector<int>& post, int post_left, int post_right) {
        if (pre_left > pre_right || post_left > post_right) return nullptr;
        
        TreeNode* node = new TreeNode(post[post_right]);
        
        if (post_right == post_left) return node;

        int index = post_left;

        while (post[index] != pre[pre_left + 1]) {
            index ++;
        }

        node->left = dfs(pre, pre_left + 1, pre_left + 1 + (index - post_left), post, post_left, index);
        node->right = dfs(pre, pre_right - (post_right - 1 - index - 1), pre_right, post, index + 1, post_right - 1);
        
        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return dfs(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
};


// @lc code=end

