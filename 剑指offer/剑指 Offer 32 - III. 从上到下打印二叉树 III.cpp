/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 14:16:22
 * @LastEditTime: 2021-01-05 14:30:39
 * @FilePath: \Leetcode\剑指 Offer 32 - III. 从上到下打印二叉树 III.cpp
 */

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
TIME:      8ms    BEAT: 51.20%    O(n) = n
MEMORY: 13.9MB    BEAT:  5.02%    O(n) = n
USED TIME:
Description: 
*/

class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* node, int depth){
        if (node == nullptr) return;
        if (res.size() == depth) res.push_back({});
        res[depth].push_back(node->val);
        if (node->left) dfs(node->left, depth + 1);
        if (node->right) dfs(node->right, depth +1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        for (int i = 0; i < res.size(); i ++) {
            if (i % 2 == 1) {
                std::reverse(res[i].begin(), res[i].end()); 
            }
        }
        return res;
    }
};
