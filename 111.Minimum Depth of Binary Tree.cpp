/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-22 15:32:29
 * @LastEditTime: 2021-03-17 15:14:25
 * @FilePath: \Leetcode\111.Minimum Depth of Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start

//Definition for a binary tree node.

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
TIME:     360ms    BEAT: 42.84%    O(n) = 
MEMORY: 141.5MB    BEAT: 33.80%    O(n) = 
LAST EDIT TIME: 2021年3月17日14:38:1
Description: 
*/

class Solution {
public:
    int minDepth(TreeNode* node) {
        if (!node) return 0;

        int left = minDepth(node->left);
        int right = minDepth(node->right);

        return !node->left || !node->right ? left + right + 1 : min(left, right) + 1;
    }
};


/*
RESULT: Accept
TIME:     420ms    BEAT: 57.20%    O(n) = 
MEMORY: 143.1MB    BEAT: 16.33%    O(n) = 
Description: DFS
*/

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if (root == nullptr)    return 0;
//         if (root->left == nullptr && root->right == nullptr)    return 1;

//         int depth1 = minDepth(root->left);
//         int depth2 = minDepth(root->right);

//         if (!root->right || !root->left) return depth1 + depth2 + 1;
        
//         return min(depth1, depth2) + 1;
//     }
// };


/*
RESULT: Accept
TIME:   520ms    BEAT:  6.12%    O(n) = 
MEMORY: 143MB    BEAT: 24.68%    O(n) = 
Description: DFS
*/

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         int ans = dfs(root, 0);
//         return ans;
//     }

// private:
//     int dfs(TreeNode* node, int depth) {
//         if (node == nullptr)    return depth + 0;
//         if (node->left == nullptr && node->right == nullptr)    return depth + 1;
//         if (node->left == nullptr)  return dfs(node->right, depth + 1);
//         if (node->right == nullptr) return dfs(node->left, depth + 1);
//         else return min(dfs(node->right, depth + 1), dfs(node->left, depth + 1));
//     }
// };

// @lc code=end