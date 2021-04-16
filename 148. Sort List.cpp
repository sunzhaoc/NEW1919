/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 14:49:09
 * @LastEditTime: 2021-03-09 15:20:06
 * @FilePath: \Leetcode\148.Sort List.cpp
 */
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
TIME:    132ms    BEAT: 66.82%    O(n) = 
MEMORY: 47.5MB    BEAT: 24.97%    O(n) = 
LAST EDIT TIME: 2021年3月9日15:20:10
Description: 
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head, * fast = head->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* left = sortList(head), * right = sortList(mid);

        ListNode* res = new ListNode(0);
        ListNode* h = res;
        while (left && right) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            }
            else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = left ? left : right;
        return res->next;
    }
};

// @lc code=end

