/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 21:10:48
 * @LastEditTime: 2021-04-06 21:22:16
 * @FilePath: \Leetcode\1669.Merge In Between Linked Lists.cpp
 */
/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:    388ms    BEAT: 40.17%    O(n) = 
MEMORY: 92.1MB    BEAT: 72.05%    O(n) = 
USED TIME: 08:03
LAST EDIT TIME: 2021年4月6日21:21:56
Description: Easy
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur = list1;
        for (int i = 0; i < a - 1; i ++) {
            cur = cur->next;
        }
        ListNode* l = cur;
        for (int i = 0; i < b - a + 1; i ++) {
            cur = cur->next;
        }
        l->next = list2;
        auto it = list2;
        for (; it->next; it = it->next);
        it->next = cur->next;
        return list1;
    }
};
// @lc code=end

