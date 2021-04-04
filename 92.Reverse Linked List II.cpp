/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 08:28:11
 * @LastEditTime: 2021-04-04 14:59:44
 * @FilePath: \Leetcode\92.Reverse Linked List II.cpp
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     8ms    BEAT: 51.4%    O(n) = 
MEMORY: 7.2MB    BEAT: 59.7%    O(n) = 
LAST EDIT TIME: 2021年3月18日9:7:21
Description: 避免分类讨论的情况。
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head, * pre = new ListNode(-1);
        ListNode* res = pre;
        pre->next = head;

        for (int i = 1; i < left; i ++) {
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = nullptr;
        ListNode* tmp1 = pre;
        ListNode* tmp2 = cur;
        
        pre = new ListNode(-1);
        pre->next = cur;
        
        for (int i = 0; i < right - left + 1; i ++) {
            ListNode* tmp3 = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp3;
        }

        tmp1->next = pre;
        tmp2->next = cur;

        return res->next;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.2MB    BEAT:  51.05%    O(n) = 
USED TIME: 33:58
LAST EDIT TIME: 2021年3月18日9:3:45
Description: 
最后返回的时候要分类讨论。
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head, * pre = new ListNode(-1);
        pre->next = head;

        for (int i = 1; i < left; i ++) {
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = nullptr;
        ListNode* tmp1 = pre;
        ListNode* tmp2 = cur;
        
        pre = new ListNode(-1);
        pre->next = cur;
        
        for (int i = 0; i < right - left + 1; i ++) {
            ListNode* tmp3 = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp3;
        }

        tmp1->next = pre;
        tmp2->next = cur;

        if (left != 1) return head;
        else return tmp1->next;
    }
};


// @lc code=end

