/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 08:47:00
 * @LastEditTime: 2021-03-16 09:21:50
 * @FilePath: \Leetcode\demo02.cpp
 */

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
TIME:    472ms    BEAT: 20.77%    O(n) = n^2
MEMORY: 14.7MB    BEAT: 86.24%    O(n) = 1
LAST EDIT TIME: 2021年3月16日9:21:8
Description: 进阶做法。时间换空间。
*/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        for (auto i = head; i != nullptr; i = i->next) {
            ListNode* pre = i;
            for (auto j = i->next; j != nullptr; j = j->next) {
                if (i->val == j->val) {
                    pre->next = j->next;
                }
                else pre = pre->next;
            }
        }
        return head;
    }
};


/*
RESULT: Accept
TIME:     32ms    BEAT: 94.30%    O(n) = n
MEMORY: 15.9MB    BEAT: 64.85%    O(n) = n
LAST EDIT TIME: 2021年3月16日9:6:30
Description: 优化了一下。
*/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        unordered_set<int> dict;
        ListNode* node = new ListNode(-1);
        node->next = head;
        for (auto i = head; i != nullptr; i = i->next) {
            if (dict.find(i->val) == dict.end()) { // Do not find
                dict.insert(i->val);
                node->next->val = i->val;
                node = node->next;                
            }
        }
        node->next = nullptr;
        return head;
    }
};


/*
RESULT: Accept
TIME:     40ms    BEAT: 76.50%    O(n) = 
MEMORY: 17.3MB    BEAT:  5.08%    O(n) = 
USED TIME: 07:08
LAST EDIT TIME: 2021年3月16日8:55:17
Description: 不难啊。但这个方法的空间有点大。
*/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        unordered_set<int> dict;
        queue<int> nums;
        for (auto i = head; i != nullptr; i = i->next) {
            if (dict.find(i->val) == dict.end()) {
                dict.insert(i->val);
                nums.push(i->val);
            }
        }
        
        ListNode* node = new ListNode(nums.front());
        nums.pop();
        ListNode* res = node;
        while (!nums.empty()) {
            node->next = new ListNode(nums.front());
            nums.pop();
            node = node->next;
        }
        return res;
    }
};