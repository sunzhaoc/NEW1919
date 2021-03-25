/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-25 15:35:21
 * @LastEditTime: 2021-03-25 16:26:49
 * @FilePath: \Leetcode\116.填充每个节点的下一个右侧节点指针.cpp
 */
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
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
TIME:   24ms    BEAT: 74.15%    O(n) = 
MEMORY: 17MB    BEAT: 13.49%    O(n) = 
USED TIME: 37:55
LAST EDIT TIME: 2021年3月25日16:26:5
Description: 二刷。前一次是用python。
层序遍历。BFS。
*/

class Solution {
public:
    vector<Node*> cur_v;
    vector<Node*> next_v;
    Node* connect(Node* root) {   
        if (!root) return nullptr;
        cur_v.push_back(root);
        while (cur_v.size() || next_v.size()) {
            for (int i = 0; i < cur_v.size(); i ++) {
                if (i == cur_v.size() - 1) cur_v[i]->next = nullptr;
                else cur_v[i]->next = cur_v[i + 1];
                if(cur_v[i]->left) next_v.push_back(cur_v[i]->left);
                if(cur_v[i]->right) next_v.push_back(cur_v[i]->right);
            }
            cur_v = next_v;
            next_v.clear();
            // cout << cur_v.size() << " " << next_v.size() << endl;
        }
        return root;
    }
};

// @lc code=end

