/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 13:32:23
 * @LastEditTime: 2021-03-31 13:36:34
 * @FilePath: \Leetcode\429.N-ary Tree Level Order Traversal.cpp
 */
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
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
TIME:     32ms    BEAT: 19.89%    O(n) = 
MEMORY: 11.7MB    BEAT: 24.02%    O(n) = 
USED TIME: 02:54 
LAST EDIT TIME: 2021年3月31日13:36:12
Description: DFS
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(Node* node, int depth) {
        if (node == nullptr) return;
        if (depth == res.size()) res.push_back({node->val});
        else res[depth].push_back(node->val);
        for (auto* it: node->children) {
            dfs(it, depth + 1);
        }
        return;
    }
};

// @lc code=end

