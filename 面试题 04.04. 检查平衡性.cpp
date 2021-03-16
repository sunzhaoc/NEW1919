/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 19:34:35
 * @LastEditTime: 2021-03-16 19:54:39
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
TIME:     12ms    BEAT: 87.67%    O(n) = 
MEMORY: 18.4MB    BEAT: 99.72%    O(n) = 
LAST EDIT TIME: 2021年3月16日19:49:26
Description: 没写出来。
*/

class Solution {
public:
    bool flag = true;

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr || flag == false) return 0;

        int l = dfs(node->left) + 1;
        int r = dfs(node->right) + 1;
        if (abs(l - r) > 1) {
            flag = false;
            node->right = nullptr;
            node->left = nullptr;
        }
        return l > r ? l : r;
    }
};