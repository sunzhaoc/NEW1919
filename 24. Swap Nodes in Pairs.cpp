/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-02 10:20:35
 * @LastEditTime: 2021-04-02 10:57:38
 * @FilePath: \Leetcode\24.Swap Nodes in Pairs.cpp
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.2MB    BEAT:  91.29%    O(n) = 
LAST EDIT TIME: 2021年4月2日10:57:29
Description: Y总。
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        for (auto p = dummy; p && p->next && p->next->next; p = p->next->next) {
            auto a = p->next, b = a->next;
            a->next = b->next;
            b->next = a;
            p->next = b;
        }
        return dummy->next;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 57.36%    O(n) = 
MEMORY: 7.4MB    BEAT: 55.67%    O(n) = 
USED TIME: 13:17
LAST EDIT TIME: 2021年4月2日10:45:6
Description: 按要求做。
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* res = head->next;
        ListNode* pre = head, * cur = head->next;
        ListNode* tmp = nullptr;
        while (1) {
            pre->next = cur->next;
            cur->next = pre;
            if (tmp) tmp->next = cur;
            tmp = cur;
            cur = pre;
            pre = tmp;
            tmp = cur;
            if (cur->next == nullptr || cur->next->next == nullptr) break;
            cur = cur->next->next;
            pre = pre->next->next;
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.3MB    BEAT:  56.48%    O(n) = 
USED TIME: 04:36
LAST EDIT TIME: 2021年4月2日10:26:46
Description: 没按规定的方法做。直接交换的节点值。
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow && fast) {
            int tmp;
            tmp = slow->val;
            slow->val = fast->val;
            fast->val = tmp;
            if (fast->next == nullptr || fast->next->next == nullptr) break;
            slow = slow->next->next;
            fast = fast->next->next;
        }
        return head;
    }
};
// @lc code=end

