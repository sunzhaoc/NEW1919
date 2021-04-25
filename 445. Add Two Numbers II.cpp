/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 16:30:50
 * @LastEditTime: 2021-04-06 18:42:42
 * @FilePath: \Leetcode\445.Add Two Numbers II.cpp
 */
/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:     28ms    BEAT: 96.38%    O(n) = n
MEMORY: 68.8MB    BEAT: 97.43%    O(n) = 1
USED TIME: 16:33
LAST EDIT TIME: 2021年4月6日18:41:22
Description: Easy
1、反转两个链表。
2、模拟相加。
3、反转。
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* id1 = l1;
        ListNode* id2 = l2;
        int a = 0;
        ListNode* tmp = new ListNode(-1);
        tmp->next = l1;
        while (id1 || id2) {
            if (id1 && id2) {
                int x = (id1->val + id2->val + a) % 10;
                a = (id1->val + id2->val + a) / 10;
                id1->val = x;
                id1 = id1->next;
                tmp = tmp->next;
                id2 = id2->next;
            }
            else if (id1) {
                int x = (id1->val + a) % 10;
                a = (id1->val + a) / 10;
                id1->val = x;
                id1 = id1->next;
                tmp = tmp->next;
            }
            else {
                int x = (id2->val + a) % 10;
                a = (id2->val + a) / 10;
                tmp->next = new ListNode(x);
                tmp = tmp->next;
                id2 = id2->next;
            }
        }
        if (a) tmp->next = new ListNode(a);
        return reverseList(l1);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

