/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 09:40:05
 * @LastEditTime: 2021-03-16 10:53:57
 * @FilePath: \Leetcode\demo.cpp
 */


// Definition for singly-linked list.
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
TIME:     4ms    BEAT: 94.86%    O(n) = 
MEMORY: 9.9MB    BEAT: 68.83%    O(n) = 
USED TIME: 03:40
LAST EDIT TIME: 2021年3月16日10:53:34
Description: 
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* node = head;
        for (auto i = head; i != nullptr; i = i ->next) {
            if (i->val < x) {
                swap(node, i);
                node = node->next;
            }
        }
        return head;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 63.99%    O(n) = 
MEMORY: 10.2MB    BEAT: 33.95%    O(n) = 
USED TIME: 04:38
LAST EDIT TIME: 2021年3月16日9:52:12
Description: 本以为能优化一下。
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<int> L, S;
        for (auto i = head; i != nullptr; i = i->next) {
            if (i->val >= x) L.push(i->val);
            else S.push(i->val);
        }
        for (auto i = head; i != nullptr; i = i ->next) {
            if (!S.empty()) {
                i->val = S.front();
                S.pop();
            }
            else {
                i->val = L.front();
                L.pop();
            }
        }
        return head;
    }
};


/*
RESULT: Accept
TIME:    8ms    BEAT: 63.99%    O(n) = 
MEMORY: 10MB    BEAT: 40.95%    O(n) = 
USED TIME: 05:01
LAST EDIT TIME: 2021年3月16日9:45:43
Description: 开了两个新TreeNode分别存储 < 和 >= 的结点。
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode(-1);
        ListNode* L = l;
        ListNode* s = new ListNode(-1);
        ListNode* S = s;

        for (auto i = head; i != nullptr; i = i->next) {
            if (i->val < x) {
                s->next = new ListNode(i->val);
                s = s->next;
            }
            else {
                l->next = new ListNode(i->val);
                l = l->next;
            }
        }
        s->next = L->next;
        return S->next;
    }
};