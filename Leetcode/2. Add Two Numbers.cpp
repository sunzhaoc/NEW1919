/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-12 10:47:24
 * @LastEditTime: 2021-01-12 14:21:58
 * @FilePath: \Leetcode\2.Add Two Numbers.cpp
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
using namespace std;


/*
RESULT: Accept
TIME:     64ms    BEAT: 20.47%    O(n) = max(m, n)
MEMORY: 70.1MB    BEAT: 11.26%    O(n) = max(m, n) + 1
USED TIME: 07:00
Description: 与下面的方法相同，简化了一下代码。
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* res = head;

        int sum;
        bool tmp = false;
        
        while (l1 || l2) {
            sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (tmp) {
                sum ++;
            }

            tmp = sum >= 10 ? true : false;

            head->next = new ListNode(sum % 10);
            head = head->next;
        }

        if (tmp) {
            head->next = new ListNode(1);
        }

        return res->next;
    }
};


/*
RESULT: Accept
TIME:   44ms    BEAT: 84.67%    O(n) = max(m, n)
MEMORY: 70MB    BEAT: 12.79%    O(n) = max(m, n) + 1 = max(m, n)
USED TIME: 22:41
Description: 
*/

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode(0);
//         ListNode* res = head;

//         int add = 0;

//         while (l1 || l2) {
//             if (l1 && l2) {
//                 head->next = new ListNode((l1->val + l2->val + add) % 10);
//                 add = (l1->val + l2->val + add) / 10;
//                 l1 = l1->next;
//                 l2 = l2->next;  
//                 head = head->next;
//             }
//             else if (l1) {
//                 head->next = new ListNode((l1->val + add) % 10);
//                 add = (l1->val + add) / 10;
//                 l1 = l1->next;
//                 head = head->next;
//             }
//             else if (l2) {
//                 head->next = new ListNode((l2->val + add) % 10);
//                 add = (l2->val + add) / 10;
//                 l2 = l2->next; 
//                 head = head->next;
//             }

//         }
//         if (add != 0 ) {
//             head->next = new ListNode(add);
//         }
//         return res->next;
//     }
// };


/*
RESULT: Wrong
USED TIME: 38:00
Description: 看清题目节点数在[0,100]内，故不能直接相加。
*/

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int sum = 0;
//         int cifang = 0;
        
//         for (auto p = l1; p; p = p->next) {
//             sum += p->val * pow(10, cifang);
//             cifang ++;
//         }
//         cifang = 0;
//         for (auto p = l2; p; p = p->next) {
//             sum += p->val * pow(10, cifang);
//             cifang ++;
//         }

//         string sum2 = to_string(sum);
//         ListNode* res = new ListNode(1);
//         ListNode* ans = res;
//         for (int i = sum2.length() - 1; i >= 0; i --) {
//             res->next = new ListNode(sum2[i]-48);
//             res = res->next;
//         }
//         return ans->next;
//     }
// };

// @lc code=end

