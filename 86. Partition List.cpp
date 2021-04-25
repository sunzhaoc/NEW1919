/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 16:10:56
 * @LastEditTime: 2021-04-06 16:27:01
 * @FilePath: \Leetcode\86.Partition List.cpp
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:    4ms    BEAT: 96.08%    O(n) = n
MEMORY: 10MB    BEAT: 17.04%    O(n) = 1
USED TIME: 14:45
LAST EDIT TIME: 2021年4月6日16:26:57
Description: Easy
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallNode = new ListNode(-1);
        ListNode* largeNode = new ListNode(-1);
        ListNode* p1 = smallNode;
        ListNode* p2 = largeNode;
        
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            
            if (cur->val < x) {
                p1->next = cur;
                p1 = p1->next;
            }
            else {
                p2->next = cur;
                p2 = p2->next;
            }

            cur->next = nullptr;
            cur = tmp;            
        }
        
        p1->next = largeNode->next;
        
        return smallNode->next;
    }
};
// @lc code=end

