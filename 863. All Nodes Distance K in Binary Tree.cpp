/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-08 14:33:47
 * @LastEditTime: 2021-01-08 15:21:22
 * @FilePath: \Leetcode\863.All Nodes Distance K in Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 9.5MB    BEAT:  96.88%    O(n) = 
Description: https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/gai-bian-shu-de-xing-zhuang-c-si-lu-dai-ma-by-lhrs/
*/

class Solution {
public:
    vector<int> res;
    TreeNode* ne;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, target, NULL);
        collect(target, 0, K);
        collect(ne, 0, K - 1);
        return res;
    }

    bool dfs(TreeNode* node, TreeNode* target, TreeNode* father) {
        if (node == nullptr) return false;

        if (node == target) {
            ne = father;
            return true;
        }
        if (dfs(node->left, target, node)) {
            node->left = father;
            return 1;
        }
        if (dfs(node->right, target, node)) {
            node->right = father;
            return 1;
        }
        return 0;
    }
    
    void collect(TreeNode* node, int depth, int K) {
        if (node == nullptr) return;
        if (depth == K) res.push_back(node->val);
        else {
            collect(node->left, depth + 1, K);
            collect(node->right, depth + 1, K);
        }
        return;
    }
};

// @lc code=end

