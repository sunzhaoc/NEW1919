/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-02 09:53:41
 * @LastEditTime: 2021-04-02 10:18:19
 * @FilePath: \Leetcode\237.Delete Node in a Linked List.cpp
 */
/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
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
TIME:    16ms    BEAT: 18.41%    O(n) = 
MEMORY: 7.6MB    BEAT: 24.09%    O(n) = 
USED TIME: 03:33
LAST EDIT TIME: 2021年4月2日10:16:50
Description: 这题值得再看看。这题的目的是实现一个fun功能。而不是给你一个头节点和要删除的节点。！！！！
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// @lc code=end

