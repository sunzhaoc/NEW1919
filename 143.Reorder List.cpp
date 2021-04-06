/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 08:53:14
 * @LastEditTime: 2021-04-06 10:22:58
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
TIME:     44ms    BEAT: 89.52%    O(n) = n
MEMORY: 17.3MB    BEAT: 80.98%    O(n) = 1
USED TIME: 17:13
LAST EDIT TIME: 2021年4月6日10:20:25
Description: 
寻找链表中点 + 链表逆序 + 合并链表
1.找到原链表的中点（参考「876. 链表的中间结点」）。
2.将原链表的右半端反转（参考「206. 反转链表」）。
3.将原链表的两端合并。
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        // 1、 寻找链表中点。
        ListNode* slow = head, * fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tmp = slow;
        slow = slow->next;
        tmp->next = nullptr;

        // 2、链表后半部分逆序。
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // 3、合并链表。
        ListNode* it1 = head;
        ListNode* it2 = pre;
        while (it1 != nullptr && it2 != nullptr) {
            tmp = it1->next;
            it1->next = it2;
            it1 = tmp;
            tmp = it2->next;
            it2->next = it1;
            it2 = it2->next;
        }
    }
};


/*
RESULT: Accept
TIME:     52ms    BEAT: 51.02%    O(n) = n
MEMORY: 18.6MB    BEAT: 13.60%    O(n) = n
USED TIME: 08:44
LAST EDIT TIME: 2021年4月6日9:59:58
Description: 线性表。
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        for (auto it = head; it; it = it->next) vec.emplace_back(it);
        int l = 0, r = vec.size() - 1;
        while (l < r) {
            vec[l ++]->next = vec[r];
            if (l == r) break;
            vec[r]->next = vec[l];
            r --;
        }
        vec[l]->next = nullptr;
    }
};


/*
RESULT: Accept
TIME:     52ms    BEAT: 51.02%    O(n) = n
MEMORY: 19.1MB    BEAT:  5.06%    O(n) = n
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

