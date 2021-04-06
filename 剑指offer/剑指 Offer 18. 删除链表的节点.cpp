/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-30 15:45:52
 * @LastEditTime: 2020-12-30 16:09:41
 * @FilePath: \Leetcode\剑指 Offer 18. 删除链表的节点.cpp
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 96.90%    O(n) = n
MEMORY: 9.5MB    BEAT: 54.25%    O(n) = 1
Description: 
*/

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* per_node = nullptr;
        ListNode* node = head;
        if (node->val == val) return node->next;
        while(1) {
            if (node->val == val) {
                per_node->next = node->next;
                break;
            }
            per_node = node;
            node = node->next;            
        }
        return head;
    }
};