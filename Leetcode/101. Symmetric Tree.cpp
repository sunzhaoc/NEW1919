/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-01 15:03:44
 * @LastEditTime: 2021-03-01 15:36:33
 * @FilePath: \Leetcode\101.Symmetric Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
TIME:    8ms    BEAT: 46.16%    O(n) = n
MEMORY: 16MB    BEAT: 12.09%    O(n) = n
LAST EDIT TIME: 2021年3月1日15:36:14
Description: 迭代。
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* node1 = root, * node2 = root;
        queue<TreeNode*> q;
        q.push(node1);
        q.push(node2);
        
        while(!q.empty()) {
            node1 = q.front();
            q.pop();
            node2 = q.front();
            q.pop();

            if (node1 == nullptr && node2 == nullptr) continue;
            if ((node1 == nullptr || node2 == nullptr) || (node1->val != node2->val)) return false;

            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        
        return true;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 46.16%    O(n) = n
MEMORY: 15.9MB    BEAT: 32.21%    O(n) = n
USED TIME: 07:55
LAST EDIT TIME: 2021年3月1日15:12:39
Description: 递归。
*/

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr) return true;
//         return cmp(root->left, root->right);
//     }

//     bool cmp(TreeNode* node1, TreeNode* node2) {
//         if (node1 == nullptr && node2 == nullptr) return true;
//         if (node1 == nullptr || node2 == nullptr || (node1->val != node2->val)) return false;
//         // 重点是下面这行代码。
//         return (cmp(node1->left, node2->right) && cmp(node1->right, node2->left));
//     }
// };

// @lc code=end

