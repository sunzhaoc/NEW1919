/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-26 08:50:31
 * @LastEditTime: 2021-03-26 09:01:30
 * @FilePath: \Leetcode\83.Remove Duplicates from Sorted List.cpp
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
TIME:     16ms    BEAT: 39.11%    O(n) = 
MEMORY: 11.1MB    BEAT: 83.31%    O(n) = 
USED TIME: 04:39
LAST EDIT TIME: 2021年3月26日8:59:5
Description: Easy.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre_node = new ListNode(-101);
        pre_node->next = head;
        ListNode* cur_node = head;
        while (cur_node) {
            if (cur_node->val == pre_node->val) {
                pre_node->next = cur_node->next;
                cur_node = pre_node->next;
            }
            else {
                cur_node = cur_node->next;
                pre_node = pre_node->next;
            }
        }
        return head;
    }
};

// @lc code=end

