/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 19:30:03
 * @LastEditTime: 2021-04-06 19:39:26
 * @FilePath: \Leetcode\328.Odd Even Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start

// Definition for singly-linked list.
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
TIME:     12ms    BEAT: 90.64%    O(n) = n
MEMORY: 10.3MB    BEAT: 26.85%    O(n) = 1
USED TIME: 07:29
LAST EDIT TIME: 2021年4月6日19:38:42
Description: Easy
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* jiHead = new ListNode(-1);
        ListNode* j = jiHead;
        ListNode* ouHead = new ListNode(-2);
        ListNode* o = ouHead, *pre = nullptr;

        ListNode* cur = head;
        int cnt = 0;
        while (cur) {
            cnt ++;
            ListNode* tmp = cur->next;
            if (cnt % 2 == 0) {
                o->next = cur;
                cur->next = nullptr;
                o = o->next;
            }

            else {
                j->next = cur;
                cur->next = nullptr;
                pre = j;
                j = j->next;
            }
            cur = tmp;
        }
        j->next = ouHead->next;
        return jiHead->next;
    }
};
// @lc code=end

