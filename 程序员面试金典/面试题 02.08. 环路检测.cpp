/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 13:24:35
 * @LastEditTime: 2021-03-16 13:52:50
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
TIME:     8ms    BEAT: 90.73%    O(n) = n
MEMORY: 7.5MB    BEAT: 72.57%    O(n) = 1
USED TIME: 19:01
LAST EDIT TIME: 2021年3月16日13:51:43
Description: 涉及到数学的证明。
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (1) {
            if (fast == nullptr|| fast->next == nullptr || fast->next->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
