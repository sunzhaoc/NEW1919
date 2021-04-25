/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 13:01:28
 * @LastEditTime: 2021-03-16 13:23:00
 * @FilePath: \Leetcode\demo.cpp
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
TIME:     44ms    BEAT: 95.96%    O(n) = 
MEMORY: 14.3MB    BEAT: 58.54%    O(n) = 
LAST EDIT TIME:  2021年3月16日13:22:40
Description: 和下面一个思路。写法好简单。
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, * b = headB;
        while (a != b) {
            a = a != nullptr ? a->next : headB;
            b = b != nullptr ? b->next : headA;
        }
        return a;
    }
};


/*
RESULT: Accept
TIME:     88ms    BEAT: 10.99%    O(n) = 
MEMORY: 14.3MB    BEAT: 47.68%    O(n) = 
USED TIME: 14:31
LAST EDIT TIME: 2021年3月16日13:16:30
Description: 
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* p1 = headA, * p2 = headB;
        bool a = false, b = false;
        while (1) {
            if (p1->next == p2->next && p1->next == nullptr && p1 != p2) return nullptr;
            if (p1 == p2) return p1;
            else {
                if (p1->next == nullptr) {
                    p1 = headB;
                    a = true;
                }
                else p1 = p1->next;

                if (p2->next == nullptr) {
                    p2 = headA;
                    b = true;
                }
                else p2 = p2->next;
            }
        }
    }
};