/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 14:33:36
 * @LastEditTime: 2021-03-31 16:41:27
 * @FilePath: \Leetcode\538.Convert BST to Greater Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start

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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     48ms    BEAT: 59.79%    O(n) = 
MEMORY: 32.7MB    BEAT: 47.78%    O(n) = 
USED TIME: 35:00
LAST EDIT TIME: 2021年3月31日15:12:41
Description: 二刷。前一次python。不会。细节没写好，导致整个都Wrong。中序遍历（倒序）。
*/

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
    
    int dfs(TreeNode* node, int sum) {
        if (node == nullptr) return sum;
        sum = dfs(node->right, sum);
        node->val += sum;
        sum = dfs(node->left, node->val);
        return sum;
    }
};

// @lc code=end

