/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-11 11:19:44
 * @LastEditTime: 2021-03-11 13:44:07
 * @FilePath: \Leetcode\142.Linked List Cycle II.cpp
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:    16ms    BEAT: 21.75%    O(n) = n
MEMORY: 9.2MB    BEAT: 16.23%    O(n) = n
LAST EDIT TIME: 2021年3月11日13:42:25
Description: 哈希表。。。空间复杂度高了啊。
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) return head;
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 91.03%    O(n) = N
MEMORY: 7.5MB    BEAT: 61.28%    O(n) = 1
LAST EDIT TIME: 2021年3月11日13:35:51
Description: 想到了双指针，但是具体的推导还是没做出来。公式推导看下面。
https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *pre = head;
                while (pre != slow) {
                    pre = pre->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

// @lc code=end

