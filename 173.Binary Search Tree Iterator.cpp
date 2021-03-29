/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-01 20:25:54
 * @LastEditTime: 2021-03-29 13:42:26
 * @FilePath: \Leetcode\173.Binary Search Tree Iterator.cpp
 */
/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start

//  * Definition for a binary tree node.
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
TIME:     36ms    BEAT: 60.32%    O(n) = 
MEMORY: 23.5MB    BEAT: 70.51%    O(n) = 
USED TIME: 03:40
LAST EDIT TIME: 2021年3月29日13:37:9
Description: 二刷。中序遍历。Easy.
*/

class BSTIterator {
public:
    vector<int> res;
    int i = 0;
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    }
    int next() {
        return res[i ++];
    }
    
    bool hasNext() {
        return i < res.size();
    }
};


/*
RESULT: Accept
LAST EDIT TIME: 2020年12月01日 20:40:36
Description: 
*/

// class BSTIterator {
// public:
//     vector<int> res;
//     int i = 0;
    
//     BSTIterator(TreeNode* root) {
//         dfs(root);
//     }
    
//     void dfs(TreeNode* node){
//         if (!node) return;
//         dfs(node->left);
//         res.push_back(node->val);
//         dfs(node->right);
//     }

//     /** @return the next smallest number */
//     int next() {
//         return res[i++];
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         return i < res.size() ;
//     }
// };


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

