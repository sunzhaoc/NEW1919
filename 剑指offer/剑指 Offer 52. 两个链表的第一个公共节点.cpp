/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 20:10:26
 * @LastEditTime: 2021-01-05 20:17:20
 * @FilePath: \Leetcode\剑指 Offer 52. 两个链表的第一个公共节点.cpp
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:     60ms    BEAT: 26.46%    O(n) = n
MEMORY: 14.6MB    BEAT: 72.55%    O(n) = 1
USED TIME: 04:37
Description: 
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;

        while (node1 != node2) {
            node1 = node1 != nullptr ? node1->next : headB;
            node2 = node2 != nullptr ? node2->next : headA;
        }

        return node1;
    }
};
