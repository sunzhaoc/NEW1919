/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-20 22:14:51
 * @LastEditTime: 2021-03-01 09:59:18
 * @FilePath: \Leetcode\104.Maximum Depth of Binary Tree.cpp
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
using namespace std;


/*
RESULT: Accept
TIME:       8s    BEAT: 88.67%    O(n) = n
MEMORY: 18.3MB    BEAT: 85.21%    O(n) = height
USED TIME: 04:01
LAST EDIT TIME: 2021年3月1日9:50:55
Description: 
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int depth) {
        if (node == nullptr) return depth;
        depth ++;
        return max(dfs(node->left, depth), dfs(node->right, depth));
    }
};