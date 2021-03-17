/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 20:45:43
 * @LastEditTime: 2021-03-16 21:11:51
 * @FilePath: \Leetcode\面试题 04.08. 首个共同祖先.cpp
 */



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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
RESULT: Accept
TIME:   20ms    BEAT: 73.03%    O(n) = 
MEMORY: 14MB    BEAT: 66.34%    O(n) = 
LAST EDIT TIME: 2021年3月16日21:11:14
Description: 
https://leetcode-cn.com/problems/first-common-ancestor-lcci/solution/di-gui-jie-fa-python-3-c-by-z1m/
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (p == node || q == node || node == nullptr) return node;
        TreeNode* left = lowestCommonAncestor(node->left, p, q);
        TreeNode* right = lowestCommonAncestor(node->right, p, q);
        if (left && right) return node;
        return left ? left : right;
    }
};


/*
RESULT: Accept
TIME:    8ms    BEAT: 100.00%    O(n) = 
MEMORY: 14MB    BEAT:  67.16%    O(n) = 
LAST EDIT TIME: 2021年3月16日21:0:34
Description: 不会啊。
*/

class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) return false;
        bool lson = dfs(node->left, p, q);
        bool rson = dfs(node->right, p, q);

        if ((lson && rson) || node->val == p->val || node->val == q->val) ans = node;
        return lson || rson || node->val == p->val || node->val == q->val;
    }
};