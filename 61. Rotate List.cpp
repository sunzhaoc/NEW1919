/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-27 14:23:20
 * @LastEditTime: 2021-04-02 11:06:46
 * @FilePath: \Leetcode\61.Rotate List.cpp
 */
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:      8ms    BEAT: 82.17%    O(n) = 
MEMORY: 11.4MB    BEAT: 44.80%    O(n) = 
USED TIME: 29:51
LAST EDIT TIME: 2021年3月27日14:54:11
Description: 
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        if (k == 0) return head;

        int len = 0;
        for (auto it = head; it != nullptr; it = it->next) {
            len ++;
        }
 
        k = k % len;
        if (k == 0) return head;

        ListNode* fast = head;
        for (int i = 0; i < len - k - 1; i ++) {
            fast = fast->next;
        }
        ListNode* res = fast->next;
        fast->next = nullptr;
        for (auto it = res; it != nullptr; it = it->next) {
            if (it->next == nullptr) {
                it->next = head;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

