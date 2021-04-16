/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-01 16:11:01
 * @LastEditTime: 2021-03-01 16:28:14
 * @FilePath: \Leetcode\543.Diameter of Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:     16ms    BEAT: 54.35%    O(n) = 
MEMORY: 19.8MB    BEAT: 71.38%    O(n) = 
USED TIME: 13:17
LAST EDIT TIME: 2021年3月1日16:27:8
Description: 
*/

class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        dfs(root);
        return ans - 1;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1; // 该节点为根的子树的深度。
    }
};

// @lc code=end

