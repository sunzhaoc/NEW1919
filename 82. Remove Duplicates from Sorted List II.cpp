/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 08:26:05
 * @LastEditTime: 2021-03-25 08:56:39
 * @FilePath: \Leetcode\82.Remove Duplicates from Sorted List II.cpp
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
TIME:      8ms    BEAT: 84.65%    O(n) = 
MEMORY: 10.7MB    BEAT: 77.04%    O(n) = 
USED TIME: 12:14
LAST EDIT TIME: 2021年3月25日8:55:59
Description: 写的有点乱。
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(INT_MIN);
        res->next = head;

        ListNode* pre = res;
        ListNode* insertNode = res;
        for (auto it = head; it != nullptr; it = it->next) {
            if ((it->next && it->next->val == it->val) || (pre->val == it->val)) {
                ListNode* tmp = pre->next;
                pre->next = nullptr;
                pre = tmp;
            }
            else {
                insertNode->next = it;
                insertNode = insertNode->next;
                pre = pre->next;
            }
        }
        return res->next;
    }
};

// @lc code=end

