/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 16:36:08
 * @LastEditTime: 2020-12-30 17:08:28
 * @FilePath: \Leetcode\剑指 Offer 24. 反转链表.cpp
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 54.35%    O(n) = n
MEMORY: 8.6MB    BEAT: 19.26%    O(n) = n
Description: 递归。
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return backTrack(nullptr, head);
    }

private:
    ListNode* backTrack(ListNode* per_node, ListNode* node) {
        if (node == nullptr) return per_node;
        ListNode* ans = backTrack(node, node->next);
        node->next = per_node;
        return ans;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 99.71%    O(n) = n
MEMORY: 8.6MB    BEAT: 30.93%    O(n) = 1
Description: 迭代。双指针。
*/

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* node_left = nullptr;
//         ListNode* node_right = head;
//         ListNode* temp = head;

//         while(node_right != nullptr) {
//             temp = node_right->next;
//             node_right->next = node_left;
//             node_left = node_right;
//             node_right = temp;
//         }
//         return node_left;
//     }
// };