/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 20:14:53
 * @LastEditTime: 2021-01-18 20:36:56
 * @FilePath: \Leetcode\1214.Two Sum BSTs.cpp
 */

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
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     28ms    BEAT: 100.00%    O(n) = 
MEMORY: 28.2MB    BEAT:  84.75%    O(n) = 
USED TIME: 18:18
LAST EDIT TIME: 2021年1月18日20:34:58
Description: 中序遍历。我以为能有什么好方法呢。。。。笑死。
*/

class Solution {
public:
    vector<int> list1, list2;

    void dfs1(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs1(node->left);
        list1.push_back(node->val);
        dfs1(node->right);
    }

    void dfs2(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        dfs2(node->left);
        list2.push_back(node->val);
        dfs2(node->right);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs1(root1);
        dfs2(root2);
        int i = 0, j = list2.size() - 1;
        while (i < list1.size() && j >= 0) {
            if (list1[i] + list2[j] > target) {
                j --;
            }
            else if (list1[i] + list2[j] < target) {
                i ++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
