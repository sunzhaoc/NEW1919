/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 09:22:57
 * @LastEditTime: 2021-03-16 09:34:10
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
TIME:      0ms    BEAT: 100.00%    O(n) = 
MEMORY: 10.3MB    BEAT:  38.41%    O(n) = 
LAST EDIT TIME: 2021年3月16日9:33:27
Description: 栈。
*/

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        stack<int> st;
        for (auto i = head; i != nullptr; i = i->next) {
            st.push(i->val);
        }
        for (int i = 0; i < k - 1; i ++) st.pop();
        return st.top();
    }
};


/*
RESULT: Accept
TIME:      0ms    BEAT: 100.00%    O(n) = 
MEMORY: 10.2MB    BEAT:  48.98%    O(n) = 
LAST EDIT TIME: 2021年3月16日9:31:2
Description: 双指针。fast先走k步，当fast=nullptr时，slow正好是倒数第k个。
*/

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head, * fast = head;
        for (int i = 0; i < k; i ++) fast = fast->next;
        for (auto i = fast; i != nullptr; i = i ->next) {
            slow = slow->next;
        }
        return slow->val;

    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 18.41%    O(n) = 
MEMORY: 10.1MB    BEAT: 81.98%    O(n) = 
USED TIME: 02:39
LAST EDIT TIME: 2021年3月16日9:26:15
Description: 
*/

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        int n = 0;
        for (auto i = head; i != nullptr; i = i->next) {
            n ++;
        }
        n = n - k + 1;
        
        int tmp = 0;
        for (auto i = head; i != nullptr; i = i->next) {
            tmp ++;
            if (tmp == n) return i->val;
        }
        return -1;
    }
};