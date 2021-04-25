/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 10:54:17
 * @LastEditTime: 2021-03-16 12:27:57
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
TIME:     68ms    BEAT:  6.91k%    O(n) = 
MEMORY: 69.2MB    BEAT: 73.13%    O(n) = 
USED TIME: 16:58
LAST EDIT TIME: 2021年3月16日12:27:30
Description: 
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0;
        ListNode* l = new ListNode(-1);
        ListNode* res = l;

        while (l1 && l2) {
            l->next = new ListNode((l1->val + l2->val + a) % 10);
            a = (l1->val + l2->val + a) / 10;
            l1 = l1->next;
            l2 = l2->next;
            l = l->next;
        }

        while (l1) {
            l->next = new ListNode((l1->val + a) % 10);
            a = (l1->val + a) / 10;
            l1 = l1->next;
            l = l->next;
        }

        while (l2) {
            l->next = new ListNode((l2->val + a) % 10);
            a = (l2->val + a) / 10;
            l2 = l2->next;
            l = l->next;
        }

        if (a != 0) l->next = new ListNode(a);
        return res->next;
    }
    
};