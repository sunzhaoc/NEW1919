/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 15:06:04
 * @LastEditTime: 2021-01-05 15:34:45
 * @FilePath: \Leetcode\剑指 Offer 34. 二叉树中和为某一值的路径.cpp
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
TIME:     16ms    BEAT: 62.85%    O(n) = n
MEMORY: 19.9MB    BEAT: 52.17%    O(n) = n
USED TIME: 25:49
Description: 
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void findPath(TreeNode* node, vector<int>& path, int a) {
        if (node == nullptr) return;
        
        a -= node->val;
        if (a == 0 && !(node->right) && !(node->left)) {
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }

        if (node->left) {
            path.push_back(node->val);
            findPath(node->left, path, a);
            path.pop_back();
        }

        if (node->right) {
            path.push_back(node->val);
            findPath(node->right, path, a);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path = {};
        findPath(root, path, sum);
        return res;
    }
};
