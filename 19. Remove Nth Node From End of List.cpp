/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-02 16:14:16
 * @LastEditTime: 2021-03-02 18:36:23
 * @FilePath: \Leetcode\19.Remove Nth Node From End of List.cpp
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 48.98%    O(n) = n
MEMORY: 10.5MB    BEAT: 56.30%    O(n) = 1
LAST EDIT TIME: 2021年3月2日18:35:4
Description: 在原链表开头新建一个节点。可避免下面的两种情况。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = new ListNode(-1);
        node->next = head;
        
        auto slow = node, fast = node;
        
        for (int i = 0; i < n; i ++) {
            fast = fast->next;
        }

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        
        return node->next;
    }
};


/*
RESULT: Accepts
TIME:      0ms    BEAT: 100.00%    O(n) = n
MEMORY: 10.4MB    BEAT:  83.05%    O(n) = 1
USED TIME: About 25 min.
LAST EDIT TIME: 2021年3月2日17:13:58
Description: 快慢指针。快指针先移动n步，保证快慢指针之间间隔永远是n，当快指针到nullptr时，慢指针到达倒数第n个。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* item = nullptr;
        int num = 0;
        for (auto it = head; it; it = it->next) {
            num ++;
            if (n == 0) {
                item = it;
                break;
            }
            n --;
        }
        if (item == nullptr && n == 0 && num == 1) return nullptr;    // 1、只有一个数的时候。
        if (item == nullptr && n == 0 && num > 1) return head->next;    // 2、当删除的是第一个数的时候。
        
        auto tmp = head;
        for (auto it = item; it->next; it = it->next) {
            tmp = tmp->next;
        }
        
        tmp->next = tmp->next->next;

        return head;
    }
};


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) < 2n
MEMORY: 10.4MB    BEAT:  73.73%    O(n) = 1
LAST EDIT TIME: 2021年3月2日16:40:4
Description: 一开始这么写报错，不知道咋回事。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int num = 0;
        for (auto it = head; it; it = it->next) {
            num ++;
        }

        if (num == 1 && n == 1) return nullptr;    // 1、只有一个数的时候。
        num -= n;
        if (num == 0) return head->next;    // 2、当删除的是第一个数的时候。

        int num2 = 0;
        for (auto it = head; it; it = it->next) {
            num2 += 1;
            if (num2 == num) {
                it->next = it->next->next;
                break;
            }
        }
        return head;
    }
};


/*
RESULT: Accept
TIME:      4ms    BEAT: 87.34%    O(n) < 2n
MEMORY: 10.3MB    BEAT: 89.29%    O(n) = 1
USED TIME: 18:46
LAST EDIT TIME: 2021年3月2日16:35:23
Description: 参考1721题的for循环。
两个特判：
1、只有一个数的时候。
2、当删除的是第一个数的时候。
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int num = 0;
        for (auto it = head; it; it = it->next) {
            num ++;
        }

        if (num == 1 && n == 1) return nullptr;    // 1、只有一个数的时候。
        num -= n;
        if (num == 0) return head->next;    // 2、当删除的是第一个数的时候。

        auto it = head;
        for (int i = 1; i <= num + n; i ++) {
            if (i == num) {
                it->next = it->next->next;
                break;
            }
            it = it->next;
        }
        
        return head;
    }
};

// @lc code=end

