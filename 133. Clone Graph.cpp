/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-30 12:37:43
 * @LastEditTime: 2021-01-30 15:35:50
 * @FilePath: \Leetcode\133.Clone Graph.cpp
 */
/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 98.44%    O(n) = 
MEMORY: 8.6MB    BEAT: 93.15%    O(n) = 
LAST EDIT TIME: 2021年1月30日15:35:49
Description: 
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node = nullptr) return nullptr;
        stack<Node*> stack;
        vector<Node*> nodes(102);
        for (int i = 0; i < 102; i ++) {
            nodes[i] = new Node();
        }
        stack.push(node);

        while (!stack.empty()) {
            Node* cur = stack.top();
            stack.pop();
            int val = cur->val;
            if (nodes[val]->val == 0) {
                nodes[val]->val = val;
            
                for (auto it: cur->neighbors) {
                    (nodes[val]->neighbors).push_back(nodes[it->val]);
                    stack.push(it);
                }
            }
        }
        return nodes[node->val];
    }
};
// @lc code=end

