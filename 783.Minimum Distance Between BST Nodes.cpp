/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-01 14:43:18
 * @LastEditTime: 2021-04-01 14:54:49
 * @FilePath: \Leetcode\783.Minimum Distance Between BST Nodes.cpp
 */
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
TIME:     4ms    BEAT: 67.75%    O(n) = 
MEMORY: 9.6MB    BEAT: 28.90%    O(n) = 
USED TIME: 08:10
LAST EDIT TIME: 2021年4月1日14:54:23
Description: 二刷。前一次是python。 审题错误。花了点时间。
*/

class Solution {
public:
    vector<int> res;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for (int i = 1; i < res.size(); i ++) ans = min(ans, abs(res[i] - res[i - 1]));
        return ans;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    }
};

// @lc code=end

