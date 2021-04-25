/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 18:32:43
 * @LastEditTime: 2021-03-31 18:40:42
 * @FilePath: \Leetcode\637.Average of Levels in Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
TIME:     12ms    BEAT: 95.51%    O(n) = 
MEMORY: 22.8MB    BEAT:  5.03%    O(n) = 
USED TIME: 06:15
LAST EDIT TIME: 2021年3月31日18:40:15
Description: 二刷。前一次python。
Easy.层序遍历。
*/

class Solution {
public:
    vector<double> res;
    vector<vector<int>> nums;
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        for (int i = 0; i < nums.size(); i ++) {
            res.push_back(ave(nums[i]));
        }
        return res;
    }
    
    double ave(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto i: nums) sum += i;
        return 1.0 * sum / n;
    }
    void dfs(TreeNode* node, int depth){
        if (node == nullptr) return;
        if (res.size() == depth) nums.push_back({node->val});
        else nums[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        return;
    }
};
// @lc code=end

