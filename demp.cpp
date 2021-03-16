/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 20:07:22
 * @LastEditTime: 2021-03-16 20:23:23
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 
LAST EDIT TIME: 
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
        if (node == nullptr) return;

        dfs(node->left, p);
                if (node == p) flag == true;
        if (flag) {
            flag = false;
            res = node;
        }

        dfs(node->right, p);
        return;
    }
};