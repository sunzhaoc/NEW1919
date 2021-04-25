/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 09:34:59
 * @LastEditTime: 2021-03-16 09:38:51
 * @FilePath: \Leetcode\dempo.cpp
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
TIME:     8ms    BEAT: 95.25%    O(n) = 
MEMORY: 7.5MB    BEAT: 70.25%    O(n) = 
USED TIME: 02:39
LAST EDIT TIME: 2021年3月16日9:38:16
Description: 这个题目表述不清。
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};