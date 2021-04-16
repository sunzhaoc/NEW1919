/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-01 16:30:02
 * @LastEditTime: 2021-03-01 16:50:49
 * @FilePath: \Leetcode\141.Linked List Cycle.cpp
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:    12ms    BEAT: 51.96%    O(n) = n
MEMORY: 7.9MB    BEAT: 52.46%    O(n) = 1
LAST EDIT TIME: 2021年3月1日16:42:41
Description: 双指针。快慢指针。U1S1我是没想到这个方法会比下面的快。
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 如果链表没有节点或就一个节点，则构不成环形链表。
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head, * fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 11.65%    O(n) = n
MEMORY: 10.3MB    BEAT:  5.02%    O(n) = n
USED TIME: 04:35
LAST EDIT TIME: 2021年3月1日16:35:59
Description: 哈希。
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }

        return false;
    }
};

// @lc code=end

