/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-01 19:52:54
 * @LastEditTime: 2021-03-01 20:23:26
 * @FilePath: \Leetcode\1457.Pseudo-Palindromic Paths in a Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
using namespace std;


/*
RESULT: Accept
TIME:   444ms    BEAT: 28.32%    O(n) = 
MEMORY: 174MB    BEAT: 66.96%    O(n) = 
USED TIME: 28:06
LAST EDIT TIME: 2021年3月1日20:23:31
Description: 
*/

class Solution {
public:
    unordered_map<int, int> map;
    int ans = 0;
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        map[node->val] ++;
        
        if (node->left == nullptr && node->right == nullptr) {
            calPath();
            map[node->val] --;
            return;
        }
        dfs(node->left);
        dfs(node->right);
        map[node->val] --;
        return;
    }

    void calPath() {
        int tmp = 0;
        for (int i = 1; i <= 9; i ++) {
            if (map[i] % 2 == 1) tmp ++;
        }
        if (tmp <= 1) ans ++;
    }
};
// @lc code=end

