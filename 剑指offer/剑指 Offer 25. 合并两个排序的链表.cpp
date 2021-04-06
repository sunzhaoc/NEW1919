/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-30 17:09:19
 * @LastEditTime: 2020-12-30 20:17:53
 * @FilePath: \Leetcode\剑指 Offer 25. 合并两个排序的链表.cpp
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 55.30%    O(n) =
MEMORY: 19.2MB    BEAT: 40.20%    O(n) = 
Description: 递归。
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


/*
RESULT: Accept
TIME:     36ms    BEAT: 91.48%    O(n) = m + n
MEMORY: 19.1MB    BEAT: 63.70%    O(n) = 1
Description: 迭代。
*/

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if (!l1) return l2;
//         if (!l2) return l1;

//         ListNode *dummy = new ListNode(0);
//         ListNode *res = dummy;
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                 res->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 res->next = l2;
//                 l2 = l2->next;
//             }
//             res = res->next;
//         }
//         res->next = l1 ? l1 : l2;
//         return dummy->next;
//     }
// };
