/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-06 16:27:51
 * @LastEditTime: 2021-04-06 16:30:08
 * @FilePath: \Leetcode\1290.Convert Binary Number in a Linked List to Integer.cpp
 */
/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 44.72%    O(n) = n
MEMORY: 7.9MB    BEAT: 75.51%    O(n) = 1
USED TIME: 00:58
LAST EDIT TIME: 2021年4月6日16:29:52
Description: 
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int cnt = 0;
        for (auto it = head; it; it = it->next) {
            cnt = cnt * 2 + it->val;
        }
        return cnt;
    }
};
// @lc code=end

