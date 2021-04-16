/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-25 16:33:15
 * @LastEditTime: 2021-03-25 16:55:18
 * @FilePath: \Leetcode\117.Populating Next Right Pointers in Each Node II.cpp
 */
/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
TIME:     16ms    BEAT: 68.51%    O(n) = n
MEMORY: 16.9MB    BEAT: 87.83%    O(n) = 1
LAST EDIT TIME: 2021年3月25日16:54:33
Description: 这个方法不错的。
*/

class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if (last) last->next = p;
        if (!nextStart) nextStart = p;
        last = p;
    }

    Node* connect(Node* root) {   
        if (!root) return nullptr;
        Node* start = root;
        while (start) {
            Node* last = nullptr, * nextStart = nullptr;
            for (auto p = start; p != nullptr; p = p->next) {
                if (p->left) handle(last, p->left, nextStart);
                if (p->right) handle(last, p->right, nextStart);
            }
            start = nextStart;
        }
        return root;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 15.57%    O(n) = n
MEMORY: 17.3MB    BEAT: 21.01%    O(n) = n
USED TIME: 00:00
LAST EDIT TIME: 2021年3月25日16:33:43
Description: 二刷。前一遍是用python。
写116题的时候就没用到完美二叉树的条件。所以直接就过了。
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

