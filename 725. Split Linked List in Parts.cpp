/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 19:40:27
 * @LastEditTime: 2021-04-06 19:55:51
 * @FilePath: \Leetcode\725.Split Linked List in Parts.cpp
 */
/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
TIME:     8ms    BEAT: 86.15%    O(n) = 
MEMORY: 8.7MB    BEAT: 64.53%    O(n) = 
USED TIME: 09:55
LAST EDIT TIME: 2021年4月6日19:55:5
Description: 我还准备好好检查一下，没想到就过了。
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        int cnt = 0;
        for (auto it = root; it; it = it->next) cnt ++;
        int a = cnt % k; // 表示前多少个部分，需要数量加 1.
        cnt = cnt / k; // 表示每部分的大小。
        int b = k - a;
        auto cur = new ListNode(-1);
        cur->next = root;
        for (int i = 0; i < a; i ++) {
            ListNode* res = cur->next;
            for (int j = 0; j < cnt + 1; j ++) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            ans.push_back(res);
            cur = new ListNode(-1);
            cur->next = tmp;
        }
        for (int i = 0; i < b; i ++) {
            ListNode* res = cur->next;
            for (int j = 0; j < cnt; j ++) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            ans.push_back(res);
            cur = new ListNode(-1);
            cur->next = tmp;
        }
        return ans;
    }
};
// @lc code=end

