/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 20:07:22
 * @LastEditTime: 2021-03-16 20:41:39
 * @FilePath: \Leetcode\demp.cpp
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
TIME:     36ms    BEAT: 64.48%    O(n) = 
MEMORY: 22.4MB    BEAT: 51.25%    O(n) = 
LAST EDIT TIME: 2021年3月16日20:41:5
Description: BST + 递归。
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* node, TreeNode* p) {
        if (node == nullptr || p == nullptr) return nullptr;
        if (p->val >= node->val) {
            return inorderSuccessor(node->right, p);
        }
        else {
            TreeNode* left = inorderSuccessor(node->left, p);
            return left ? left : node;
        }
    }
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 24.65%    O(n) = 
MEMORY: 22.4MB    BEAT: 57.10%    O(n) = 
USED TIME: 19:35
LAST EDIT TIME: 2021年3月16日20:28:9
Description: 
*/

class Solution {
public:
    TreeNode* res = nullptr;
    bool flag = false;

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return res;
    }

    void dfs(TreeNode* node, TreeNode* p) {
        if (node == nullptr || res != nullptr) return;

        dfs(node->left, p);
        if (flag == true) {
            res = node;
            flag = false;
            return;
        }
        if (node == p) flag = true;
        dfs(node->right, p);
        return;
    }
};