/*
 * @Description: // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 12:33:04
 * @LastEditTime: 2021-03-16 13:00:58
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
TIME:     20ms    BEAT: 66.30%    O(n) = n
MEMORY: 13.4MB    BEAT: 74.91%    O(n) = 1
USED TIME: 21:05
LAST EDIT TIME: 2021年3月16日12:58:21
Description: 1、用快慢指针找到链表的中心。2、翻转后面。3、比较。
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        // Prat 1
        ListNode* slow = head, * fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Part 2: 反转链表
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* tmp;
        
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;  
        }      

        // Part 3
        while (pre && head) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        
        return true;
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 85.92%    O(n) = n
MEMORY: 13.7MB    BEAT: 67.46%    O(n) = n
USED TIME: 02:07
LAST EDIT TIME: 2021年3月16日12:36:3
Description: 将值复制到数组中后用双指针法
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        for (auto i = head; i != nullptr; i = i->next) {
            v.emplace_back(i->val);
        }
        for (int i = 0, j = v.size() - 1; i < j; i ++, j --) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};