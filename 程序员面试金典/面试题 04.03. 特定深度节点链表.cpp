/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 16:50:54
 * @LastEditTime: 2021-03-16 19:32:02
 * @FilePath: \Leetcode\demp.cpp
 */


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 8.5MB    BEAT:   8.01%    O(n) = 
LAST EDIT TIME: 2021年3月16日19:31:23
Description: 优化了一下代码。
*/

class Solution {
public:
    vector<ListNode*> topNode;
    vector<ListNode*> backNode;

    vector<ListNode*> listOfDepth(TreeNode* tree) {
        dfs(tree, 0);
        return topNode;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth == topNode.size()) {
            ListNode* tmp = new ListNode(node->val);
            topNode.push_back(tmp);
            backNode.push_back(tmp);
        }
        else {
            backNode[depth]->next = new ListNode(node->val);
            backNode[depth] = backNode[depth]->next;
        };

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        return;
    }
};



/*
RESULT: Accept
TIME:     4ms    BEAT: 54.59%    O(n) = 
MEMORY: 8.5MB    BEAT:  9.52%    O(n) = 
USED TIME: 没记录。
LAST EDIT TIME: 2021年3月16日17:9:12
Description: 
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        dfs(tree, 0);
        vector<ListNode*> ans;

        for (int i = 0; i < res.size(); i ++) {
            ListNode* tmp = new ListNode(res[i][0]);
            ListNode* head = tmp;
            for (int j = 1; j < res[i].size(); j ++) {
                tmp->next = new ListNode(res[i][j]);
                tmp = tmp->next;
            }
            ans.push_back(head);
        }

        return ans;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth == res.size()) res.push_back({node->val});
        else res[depth].push_back(node->val);

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
        return;
    }
};