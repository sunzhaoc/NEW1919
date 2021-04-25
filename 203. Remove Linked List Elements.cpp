/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 11:04:50
 * @LastEditTime: 2021-04-06 11:15:06
 * @FilePath: \Leetcode\203.Remove Linked List Elements.cpp
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

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
TIME:     20ms    BEAT: 97.99%    O(n) = n
MEMORY: 14.6MB    BEAT: 67.09%    O(n) = 1
USED TIME: 08:14
LAST EDIT TIME: 2021年4月6日11:14:29
Description: Easy
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* cur = head;
        while (cur) {
            if (cur->val != val) {
                cur = cur->next;
                pre = pre->next;
                continue;
            }
            pre->next = cur->next;
            cur = cur->next;
        }
        for (auto it = head; it; it = it->next) {
            if (it->val != val) return it;
        }
        return nullptr;
    }
};
// @lc code=end

