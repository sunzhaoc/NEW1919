/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-30 16:48:43
 * @LastEditTime: 2021-03-01 19:32:32
 * @FilePath: \Leetcode\206.Reverse Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 77.02%    O(n) = n
MEMORY: 8.1MB    BEAT: 73.44%    O(n) = 1
USED TIME: 01:13
LAST EDIT TIME: 2021年3月1日19:26:37
Description: 二刷。
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};


/*
RESULT: Accept
TIME:    12ms    BEAT: 53.35%    O(n) = n
MEMORY: 8.6MB    BEAT: 41.13%    O(n) = 1
Description: 
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

// @lc code=end

