/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 08:53:14
 * @LastEditTime: 2021-04-06 09:28:55
 * @FilePath: \Leetcode\143.Reorder List.cpp
 */
/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
TIME:     52ms    BEAT: 51.02%    O(n) = 
MEMORY: 19.1MB    BEAT:  5.06%    O(n) = 
USED TIME: 25:31
LAST EDIT TIME: 2021年4月6日9:27:6
Description: 
1、开新空间存翻转链表。
2、从头遍历，分奇偶讨论。
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        // 1、开新空间存翻转链表。
        ListNode* cur = head;
        ListNode* rcur;
        ListNode* rpre = nullptr;
        int cnt = 0;
        while (cur) {
            rcur = new ListNode(cur->val);
            if (rpre == nullptr) rcur->next = nullptr; 
            else rcur->next = rpre;
            cur = cur->next;
            rpre = rcur;
            cnt ++;
        }

        // 2、从头遍历，分奇偶讨论。
        ListNode* l1 = head;
        ListNode* l2 = rcur;
        for (int i = 0; i < cnt / 2; i ++) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            if (i + 1 >= cnt / 2) {
                if (cnt % 2 == 0) {
                    l2->next = nullptr;
                }
                else {
                    l2->next->next = nullptr;
                }
                break;
            }
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
// @lc code=end

