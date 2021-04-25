/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 09:30:37
 * @LastEditTime: 2021-04-06 09:42:57
 * @FilePath: \Leetcode\876.Middle of the Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
TIME:     4ms    BEAT: 34.68%    O(n) = n
MEMORY: 6.3MB    BEAT: 75.55%    O(n) = 1
USED TIME: 05:18
LAST EDIT TIME: 2021年4月6日9:37:55
Description: 双指针。
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (fast == nullptr) return head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->next;
    }
};

// @lc code=end

