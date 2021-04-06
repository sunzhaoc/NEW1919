/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-07 14:42:50
 * @LastEditTime: 2020-12-07 15:45:15
 * @FilePath: \Leetcode\剑指 Offer 06. 从尾到头打印链表.cpp
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/*
RESULT: Accept
TIME:     8ms    BEAT: 71.58%    O(n) = n
MEMORY: 8.8MB    BEAT: 59.85%    O(n) = n
Description: 改变链表结构法。
*/

class Solution {
public:
    vector<int> ans;
    vector<int> reversePrint(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *next = head;
        ListNode *cur = head;

        while (cur){
            next = cur->next;   //保存当前结点的下一个节点
            cur->next = pre;    //当前结点指向前一个节点，反向改变指针
            pre = cur;  //更新前一个节点
            cur = next; //更新当前结点
        }

        while (pre){
            ans.push_back(pre->val);
            pre = pre->next;
        }

        return ans;      
    }
};


/*
RESULT: Accept
TIME:      20ms    BEAT: 10.68%    O(n) = n
MEMORY:   9.2MB    BEAT: 16.55%    O(n) = n
Description: 堆栈法，因为输出为逆序，可以利用堆栈的性质。
*/

// class Solution {
// public:
//     vector<int> ans;
//     vector<int> reversePrint(ListNode* head) {
//         stack<int> s;
        
//         // 入栈
//         while (head){
//             s.push(head->val);
//             head = head->next;
//         }

//         // 出栈
//         while (!s.empty())
//         {
//             ans.push_back(s.top());
//             s.pop();
//         }
//         return ans;                
//     }
// };


/*
RESULT: Accept
TIME:      56ms    BEAT: 7.40%    O(n) = n
MEMORY: 248.7MB    BEAT: 5.01%    O(n) = n
Description: 递归解法。链表非常长时可能导致函数调用栈溢出。
*/

// class Solution {
// public:
//     vector<int> ans;

//     vector<int> reversePrint(ListNode* head) {
//         if (head == nullptr)    return ans;
//         reversePrint(head->next);
//         ans.push_back(head->val);
//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 8.7MB    BEAT:  73.12%    O(n) = 1
Description: 利用algorithm中的reverse函数进行反转。
*/

// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         vector<int> ans;
//         while (head)
//         {   
//             ans.push_back(head->val);
//             head = head->next;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };