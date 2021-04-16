/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-02 14:09:46
 * @LastEditTime: 2021-03-02 15:38:39
 * @FilePath: \Leetcode\114.Flatten Binary Tree to Linked List.cpp
 */


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
using namespace std;


/*
RESULT: Accept
TIME:     12ms    BEAT: 39.51%    O(n) = 
MEMORY: 12.4MB    BEAT: 79.63%    O(n) = 
LAST EDIT TIME: 2021年3月2日15:37:43
Description: 默写一遍。
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        
        if (root->left) {
            TreeNode* tmp = root->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            tmp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 11.67%    O(n) = 
MEMORY: 12.3MB    BEAT: 91.69%    O(n) = 
LAST EDIT TIME: 2021年3月2日15:31:24
Description: 
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/biao-biao-zhun-zhun-de-hou-xu-bian-li-dai-ma-jian-/
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);

        // -----------------这段就离谱--------------------
        if (root->left != nullptr) {
            auto pre = root->left;
            while (pre->right != nullptr) {
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        // ----------------------------------------------

        root = root->right; // 可以不要，没用。
    }
};


/*
RESULT: Wrong
USED TIME: 01:05:20
LAST EDIT TIME: 2021年3月2日15:16:32
Description: 不会。
*/

class Solution {
public:
    TreeNode* finNode;
    
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* ans = root;
        dfs(root, nullptr);
        root = ans;
    }

    void dfs(TreeNode* node, TreeNode* tmpNode) {
        if (!node->left && !node->right) {
            finNode = node;
            return;
        }

        if (!node->left) {
            dfs(node->right, nullptr);
        } 
        else if(!node->right) {
            node->right = node->left;
            node->left = nullptr;
            dfs(node->right, nullptr);
        }
        else {
            tmpNode = node->right;
            node->right = node->left;
            node->left = nullptr;
            dfs(node->right, tmpNode);
        }
        
        if (tmpNode != nullptr) {
            finNode->right = tmpNode;
            finNode = finNode->right;
        }
    }
};