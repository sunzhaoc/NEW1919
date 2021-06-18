/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 19:57:16
 * @LastEditTime: 2021-04-06 20:18:05
 * @FilePath: \Leetcode\369.Plus One Linked List.cpp
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 8.4MB    BEAT:  28.65%    O(n) = 1
USED TIME: 08:48
LAST EDIT TIME: 2021年4月6日20:17:24
Description: 
Point： 找到最后一个不为0的数。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* bef = new ListNode(0);
        bef->next = head;
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        if (cur->val != 9) {
            cur->val += 1;
            return head;
        }        
        ListNode* node = bef;
        for (auto it = bef; it; it = it->next) {
            if (it->val != 9) node = it;
        }
        node->val += 1;
        for (auto it = node->next; it; it = it->next) {
            it->val = 0;
        }
        return bef->val == 1 ? bef : head;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 15.20%    O(n) = 
MEMORY: 8.3MB    BEAT: 67.25%    O(n) = 
USED TIME: 08:22
LAST EDIT TIME: 2021年4月6日20:6:27
Description: 
*/

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* pre = reverseList(head);
        ListNode* cur = pre;
        int a = 1;
        ListNode* prepre = nullptr;
        while (pre) {
            if (pre->val + a >= 10) {
                pre->val = 0;
                a = 1;
                prepre = pre;
                pre = pre->next;
            }
            else {
                pre->val = pre->val + 1;
                a = 0;
                break;
            }
        }
        if (a) {
            prepre->next = new ListNode(1);
        }
        return reverseList(cur);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};