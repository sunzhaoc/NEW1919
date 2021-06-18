/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 20:42:41
 * @LastEditTime: 2021-05-30 10:58:02
 * @FilePath: \Leetcode\23. Merge k Sorted Lists.cpp
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
TIME:   20ms    BEAT: 97.28%    O(n) = 
MEMORY: 13MB    BEAT: 55.38%    O(n) = 
USED TIME: 21:17
LAST EDIT TIME: 2021年4月6日21:9:17
Description: Easy
最小堆。
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp {
            bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
                return x.first > y.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap; // val, id

        if (lists.empty()) return nullptr;
        int n;
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i] != nullptr) n ++;
        }
        if (n == 0) return nullptr;
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i] == nullptr) continue;
            minHeap.push(make_pair(lists[i]->val, i));
        }

        ListNode* node = new ListNode(-1);
        ListNode* cur = node;
        while (minHeap.size()) {
            int id = minHeap.top().second;
            // ListNode* tmp = lists[id]->next;
            cur->next = lists[id];
            cur = cur->next;
            lists[id] = lists[id]->next;
            minHeap.pop();
            if (lists[id]) minHeap.push(make_pair(lists[id]->val, id));
        }

        return node->next;
    }
};
// @lc code=end

