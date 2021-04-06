/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 10:26:09
 * @LastEditTime: 2021-04-06 11:03:41
 * @FilePath: \Leetcode\25.Reverse Nodes in k-Group.cpp
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
TIME:     12ms    BEAT: 98.45%    O(n) = n
MEMORY: 11.3MB    BEAT: 20.63%    O(n) = 1
USED TIME: 28:39
LAST EDIT TIME: 2021年4月6日10:56:50
Description: 我觉得我的代码比解答好。
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next == nullptr) return head;
        int cnt = 0;
        for (auto it = head; it; it = it->next) cnt ++;
        cnt = cnt / k;
        ListNode* res = head;
        for (int i = 0; i < k - 1; i ++) res = res->next;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        // 这部分比较难想。 lastnode表示上个已翻转部分的末位节点（翻转前是头节点）
        // thisnode 表示当前待翻转部分的头节点（经过这次翻转后为末节点）
        // 如果是第一次，则lastnode为空，前面没有可以已翻转的部分与当前刚翻转完成的部分连接。
        ListNode* lastNode = nullptr; 
        ListNode* thisNode;
        for (int i = 0; i < cnt; i ++) {
            thisNode = cur;
            pre = nullptr;
            for (int i = 0; i < k; i ++) {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            if(lastNode) lastNode->next = pre;
            lastNode = thisNode;
        }
        if (cur) lastNode->next = cur;
        return res;
    }
};

// @lc code=end

