/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 13:30:01
 * @LastEditTime: 2021-01-05 14:03:43
 * @FilePath: \Leetcode\剑指 Offer 32 - I. 从上到下打印二叉树.cpp
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include <iostream>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 42.42%    O(n) = n
MEMORY: 12.4MB    BEAT: 21.83%    O(n) = n
USED TIME: 04:50
Description: BFS
*/

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return {}; 
        
        queue<TreeNode*> Bfs;
        Bfs.push(root);
        while (!Bfs.empty())
        {
            TreeNode* temp = Bfs.front();
            res.push_back(temp->val);
            Bfs.pop();
            if (temp->left) Bfs.push(temp->left);
            if (temp->right) Bfs.push(temp->right);
        }
        return res;
    }
};