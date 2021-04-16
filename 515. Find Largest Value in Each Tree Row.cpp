/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 14:28:42
 * @LastEditTime: 2021-03-31 14:33:01
 * @FilePath: \Leetcode\515.Find Largest Value in Each Tree Row.cpp
 */
/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
TIME:      8ms    BEAT: 97.11%    O(n) = 
MEMORY: 21.5MB    BEAT: 95.14%    O(n) = 
USED TIME: 02:17
LAST EDIT TIME: 2021年3月31日14:32:26
Description: 二刷。前一次python。层序遍历。
*/

class Solution {
public:
    vector<int> res;
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (depth == res.size()) res.push_back(node->val);
        else if (node->val > res[depth]) res[depth] = node->val;
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        return;
    }
};

// @lc code=end

