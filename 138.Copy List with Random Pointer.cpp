/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 21:23:31
 * @LastEditTime: 2021-04-06 21:43:20
 * @FilePath: \Leetcode\138.Copy List with Random Pointer.cpp
 */
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:     16ms    BEAT: 27.88%    O(n) = 
MEMORY: 11.4MB    BEAT: 12.59%    O(n) = 
LAST EDIT TIME: 2021年4月6日21:42:24
Description: 
应该算是链表中最难的一题了吧。复制带随机指针的链表
本质是递归 + 链表。用哈希表来做。有意思。值得再做。
*/

class Solution {
public:
    unordered_map<Node*, Node*> dic;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (dic.count(head)) return dic[head];
        Node* root = new Node(head->val);
        dic[head] = root;
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);
        return root;
    }
};
// @lc code=end

