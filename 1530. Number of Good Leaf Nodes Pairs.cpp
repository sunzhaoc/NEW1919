/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-01 20:24:22
 * @LastEditTime: 2021-03-01 21:24:31
 * @FilePath: \Leetcode\1530.Number of Good Leaf Nodes Pairs.cpp
 */
/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
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
TIME:   100ms    BEAT: 67.45%    O(n) = 
MEMORY:  36MB    BEAT: 41.45%    O(n) = 
USED TIME: 30:00
LAST EDIT TIME: 2021年3月1日20:58:13
Description: 
*/

class Solution {
public:
    int distance;
    int ans = 0;

    int countPairs(TreeNode* root, int a) {
        distance = a;
        dfs(root);
        return ans;
    }
    
    vector<int> dfs(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            return {1};
        }

        vector<int> L, R, tmp;
        if (node->left) L = dfs(node->left);
        if (node->right) R = dfs(node->right);
        
        for (auto l: L) {
            for (auto r: R) {
                if (l + r <= distance) ans ++;
            }
        }
        
        for (auto l: L) {
            tmp.emplace_back(l + 1);
        }
        for (auto r: R) {
            tmp.emplace_back(r + 1);
        }

        return tmp;
        
    }

};

// @lc code=end

 