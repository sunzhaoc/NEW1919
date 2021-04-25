/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-14 19:07:58
 * @LastEditTime: 2021-01-14 19:28:41
 * @FilePath: \Leetcode\653.Two Sum IV - Input is a BST.cpp
 */
/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
using namespace std;


/*
RESULT: Accept
TIME:   48ms    BEAT: 99.10%    O(n) = n^2
MEMORY: 36MB    BEAT: 92.28%    O(n) = n
USED TIME: 07:15
LAST EDIT TIME: 2021年1月14日19:25:42
Description: 中序遍历 + for 循环剪枝。没啥用啊。。。
*/

class Solution {
public:
    vector<int> tmp;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        tmp.push_back(node->val);
        dfs(node->right);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        
        for (int i = 0; i < tmp.size(); i ++) {
            for (int j = i + 1; j < tmp.size(); j ++) {
                if (tmp[i] + tmp[j] == k) return true;
                else if (tmp[i] + tmp[j] > k) break;
            }
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:   48ms    BEAT: 99.10%    O(n) = n^2
MEMORY: 36MB    BEAT: 93.18%    O(n) = n
USED TIME: 07:15
LAST EDIT TIME: 2021年1月14日19:21:52
Description: 中序遍历。
*/

// class Solution {
// public:
//     vector<int> tmp;

//     void dfs(TreeNode* node) {
//         if (node == nullptr) return;
//         dfs(node->left);
//         tmp.push_back(node->val);
//         dfs(node->right);
//         return;
//     }

//     bool findTarget(TreeNode* root, int k) {
//         dfs(root);
        
//         for (int i = 0; i < tmp.size(); i ++) {
//             for (int j = i + 1; j < tmp.size(); j ++) {
//                 if (tmp[i] + tmp[j] == k) return true;
//             }
//         }
//         return false;
//     }
// };

// @lc code=end

