/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 16:11:53
 * @LastEditTime: 2020-12-30 16:34:56
 * @FilePath: \Leetcode\剑指 Offer 22. 链表中倒数第k个节点.cpp
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = n
MEMORY: 10.8MB    BEAT:  26.93%    O(n) = 1
Description: 双指针。
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* point_left = head;
        ListNode* point_right = head;

        for (int i = 0; i < k; i ++) {
            point_right = point_right->next;
        }
        
        while (point_right != nullptr) {
            point_left = point_left->next;
            point_right = point_right->next;
        }
        return point_left;
    }
};